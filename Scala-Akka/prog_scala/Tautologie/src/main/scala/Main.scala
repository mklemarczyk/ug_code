import logic._

object Main {

    def test(exprstr: String): Unit = {
        FrmParser(exprstr) match {
            case Some(frm) =>
                println(s"Reprezentacja formuły: ${frm}")
            case None => println("Niepoprawna składnia formuły")
        }
    }

    def isTautology(frm: Frm): Boolean = ???

    def main(args: Array[String]): Unit = {
        test(args(0))
    }
}

/*
    ZADANIE: napisz funkcję isTautology, która dla danej formuły rachunku
    zdań sprawdza, czy jest ona tautologią, czyli że ma wartość „true”
    dla dowolnego wartościowania występujących w niej formuł atomowych.

    Formuły reprezentowane są przez obiekty typu Frm z pakietu „logic”.

    W rozwiązaniu nie używaj zmiennych (var) oraz instrukcji pętli.

    Program główny powinien wczytywać (z linii poleceń) formułę rachunku
    zdań, a następnie sprawdzać, czy jest ona tautologią i informować
    o tym w konsoli.

    W linii poleceń SBT, można to zrobić używając np. polecenia:

    run "(a -> b) | (b -> a)"
    run "a | ~a"

*/
