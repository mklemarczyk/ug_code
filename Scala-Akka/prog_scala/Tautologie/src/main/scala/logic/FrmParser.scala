package logic

import util.parsing.combinator.lexical.StdLexical

class FrmLexical extends StdLexical {
    override def token: Parser[Token] = stringToken | super.token
    def stringToken: Parser[Token] = rep1(letter) ^^ {
        case e => StringLit(e.mkString(""))
    }
}

import util.parsing.combinator.syntactical._

object FrmParser extends StandardTokenParsers {
    override val lexical = new FrmLexical
    lexical.delimiters ++= List("|","&","->","(",")","~")

    def atom = stringLit ^^ { s => A(s) }

    def parens: Parser[Frm] = "(" ~> frm <~ ")"

    def negation: Parser[Neg] = "~" ~> term ^^ { Neg(_) }

    def term = ( atom |  parens | negation )

    def binaryOp(level: Int): Parser[((Frm,Frm)=>Frm)] = {
        level match {
            case 1 => "->" ^^^ { (a:Frm, b:Frm) => Imp(a,b) }
            case 2 => "|"  ^^^ { (a:Frm, b:Frm) => Dis(a,b) }
            case 3 => "&"  ^^^ { (a:Frm, b:Frm) => Cnj(a,b) }
            case _ => throw new RuntimeException(s"Bad precedence level $level")
        }
    }
    val minPrec = 1
    val maxPrec = 3
    def binary(level: Int): Parser[Frm] = {
        if (level>maxPrec) term
        else binary(level + 1) * binaryOp(level)
    }
    def frm = ( binary(minPrec) | term )
    def parse(s: String) = {
      val tokens = new lexical.Scanner(s)
      phrase(frm)(tokens)
  }

  def apply(s: String): Option[Frm] = {
      parse(s) match {
          case Success(tree, _) => Some(tree)
          case e: NoSuccess => None
      }
  }

}
