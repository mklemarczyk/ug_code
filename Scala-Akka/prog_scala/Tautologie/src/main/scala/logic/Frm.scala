package logic

abstract class Frm
case class A(a: String) extends Frm
case class Neg(p: Frm) extends Frm
case class Cnj(p: Frm, q: Frm) extends Frm
case class Dis(p: Frm, q: Frm) extends Frm
case class Imp(p: Frm, q: Frm) extends Frm
