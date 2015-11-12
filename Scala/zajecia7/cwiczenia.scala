package bank
/*

  Wykorzystując listę „dane” zawartą w pliku „package.scala” rozwiąż poniższe
  ćwiczenie – swój kod kompiluj za pomocą polecenia:

  scalac *.scala

  Lista zawiera informacje na temat „operacji bankowych” – jej elementami
  są pary data - kwota operacji. Kwota ujemna oznacza obciążenie rachunku
  (wydatek).

  W swoim rozwiązaniu nie używaj zmiennych (wprowadzanych za pomocą „var”)
  oraz konstrukcji „while” oraz „foreach”.

  Ćwiczenie 1: Napisz funkcję obliczającą sumaryczną wysokość wpływów i wydatków
  dla każdego z miesięcy

  Ćwiczenie 2. Napisz funkcję, która dla każdego dnia, którego data znajduje się
  w danych oblicza „balans konta”. Rozumiemy przez to wysokość sumy na koncie po
  uwzględnieniu operacji, które tego dnia zostały „zaksięgowane”. Załóż,
  że początkowy stan konta to 2500 zł.

  Ćwiczenie 3. Napisz funkcję znajdującą miesiąc(e), w którym balans wpływów
  i obciążeń rachunku był najkorzystniejszy tzn. suma wpływów pomniejszona
  o sumę obciążeń była maksymalna.

*/
object Main {
  def main(args: Array[String]): Unit = {
    println(dane.length)
  }
}
