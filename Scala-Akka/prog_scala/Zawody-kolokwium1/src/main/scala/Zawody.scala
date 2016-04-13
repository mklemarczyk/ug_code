/*
    ZADANIE: Napisz program, który obsługuje zawody sportowe w hipotetycznej
    konkurencji, w której każdy z zawodników oceniany jest w dwóch kategoriach:

      - wdzięk
      - spryt

    Oceny (dwie liczby całkowite z zakresu [0..20]) wystawiają sędziowie. Liczba
    sędziów może być różna dla różnych zawodników. Ostateczna wynik zawodnika jest
    to para liczb będących średnimi arytmetycznymi ocen sędziowskich w podanych
    powyżej kategoriach.

    Ranking ustala się sumując obie noty każdego z zawodników - wyższa suma oznacza
    lepszy wynik.

    Jeśli sumy dwóch zawodników są identyczne, to wyższe miejsce zajmuje ten, którego
    nota za wdzięk była wyższa. Jeśli również noty za wdzięk są identyczne, to zawodnicy
    zajmuja miejsca ex-aequo.

    Struktura systemu
    =================

    Na system składają się następujące elementy.

    - Aktor główny, dysponujący listą startową, listą wszystkich sędziów (każdy z nich
      jest również reprezentowany przez osobnego aktora) oraz przechowuje aktualny ranking
      zawodów.

      Dla każdego z zawodników z listy startowej, aktor główny losowo wybiera (co najmniej
      dwuelementową) grupę sędziów, którzy mają go ocenić (tzw. „zestaw sędziowski”).
      Wysyła do wszystkich sędziów z tej grupy odpowiedni komunikat (informujący ich o
      konieczności wystawienia oceny), a następnie odbiera spływające od nich wyniki.
      Po otrzymaniu wyników od wszystkich wybranych sędziów, aktualizuje ranking i wyświetla
      go na konsoli.

      Kiedy ocenieni zostaną już wszyscy zawodnicy z listy startowej, aktor główny wyświetla
      na konsoli ranking końcowy, a następnie kończy działanie całego systemu.

    - Aktor reprezentujący sędziego oczekuje na komunikat zawierający dane zawodnika do oceny.
      Kiedy taki komunikat otrzyma, generuje losową ocenę i odsyła do aktora głównego.

    - Całkowita liczba sędziów powinna być parametrem programu. Oczywiście zestawy sędziowskie
      muszą mieć liczebność nie przekraczającą całkowitej liczby sędziów. :)

    Ranking powinien zawierać informacje o:

       - miejscu zajętym przez zawodnika
       - nazwisku zawodnika
       - uzyskanym wyniku

    W przypadku miejsc ex-aequo kolejność na liście rankingowej powinna być zgodna
    z porządkiem alfabetycznym nazwisk zawodników.

    Twój program nie powinien wykorzystywać elementów imperatywnych języka
    (zmienne i pętle).

    W rozwiązaniu możesz wykorzystywać dowolne niemutowalne kolekcje języka Scala
    i wszelkie dostępne dla nich metody standardowe.

    Dla ciągu ocen postaci

            Ocena("Szabat",16,13),
            Ocena("Maliniak",16,14),
            Ocena("Bek",16,14),
            Ocena("Bek",15,15),
            Ocena("Bąk",16,14),
            Ocena("Bąk",15,15),
            Ocena("Bak",16,14),
            Ocena("Bak",15,15),
            Ocena("Nowicki",18,16),
            Ocena("Kowalski",15,15),
            Ocena("Kowalski", 13,17)

    ranking powinien wyglądać nastepująco

        1. Nowicki     : 34,00 = 18,00-16,00
        2. Maliniak    : 30,00 = 16,00-14,00
        3. Bak         : 30,00 = 15,50-14,50
        3. Bąk         : 30,00 = 15,50-14,50
        3. Bek         : 30,00 = 15,50-14,50
        6. Kowalski    : 30,00 = 14,00-16,00
        7. Szabat      : 29,00 = 16,00-13,00

*/

import akka.actor._
import java.util.Random

case class Zawodnik(naz: String) extends Ordered[Zawodnik] {
    // porównywanie napisów zgodnie z regułami języka polskiego
    override def  compare(z: Zawodnik): Int = {
        import java.util.Locale
        import java.text.Collator
        Collator.getInstance(new Locale("pl", "PL")).compare(this.naz, z.naz)
    }
}
// Zawodnik("Bak") < Zawodnik("Bąk") == true
// Zawodnik("Bek") < Zawodnik("Bąk") == false

case class Ocena(z: Zawodnik, w: Float, s: Float) extends Ordered[Ocena] {
    // ostateczny porządek w wynikach powinien być malejący (!)
    // czyli lepsza ocena jest „mniejsza” od gorszej.
    override def compare(o: Ocena): Int = {
		val wynikOrder = -(this.w + this.s).compare(o.w + o.s)
		if(wynikOrder == 0){
			z.compare(o.z)
		}else
			wynikOrder
        //  o1.compare(o2) równa się
        //  -1 gdy o1 jest mniejszy niż o2
        //   0 gdy o1 i o2 są równe
        //   1 gdy o1 jest większy niż o2
    }
}
// Po zdefiniowaniu metody compare Oceny będzie można porównywać
// stosując zwykłe operatory porównania (<, >, <=, >=), podobnie,
// jak Zawodników.

class Sedzia extends Actor {
	val random = new Random()

	def receive: Receive = {
		case Zawodnik(nazwa) => sender() ! Ocena(Zawodnik(nazwa), random.nextInt(21), random.nextInt(21)) 
	}
}

case class Ranking(oceny: List[Ocena]) {
    def drukuj() : Unit = {
		var wyniki = oceny
			.groupBy(x => x.z)
			.map(x => (
				x._1,
				x._2.map(x => x.w).sum / (x._2.length.toFloat -1),
				x._2.map(x => x.s).sum / (x._2.length.toFloat -1)
			))
			.map(x => Ocena(x._1, x._2, x._3))
			.toList
			.sorted
			.zipWithIndex
		for(wynik <- wyniki)
			println(f"${wynik._2+1}%.0f. ${wynik._1.z.naz}%-15s: ${wynik._1.w + wynik._1.s}%6.2f = ${wynik._1.w}%5.2f - ${wynik._1.s}%5.2f")
    }
}

object Zawody {
    def main(args: Array[String]): Unit = {
		import akka.actor.ActorDSL._
		val system = ActorSystem("system")
		val random = new Random()
		val liczbaSedziow = 20
		// Tworzymy "aktora programu głównego"
		actor(system, "main")(new Act {
			val listaStartowa = List("Nowicki", "Maliniak", "Bak", "Bąk", "Bek", "Kowalski", "Szabat")
				.zipWithIndex
			val ranking = new Ranking(listaStartowa
				.map(x => Ocena(Zawodnik(x._1), 0, 0)))
			val skladSedziowski = (0 to liczbaSedziow)
				.map(x => context.actorOf(Props[Sedzia], s"Sedzia$x"))
			for(imie <- listaStartowa){
				var sedziowie = WybierzSkladSedziowski()
				for(sedzia <- sedziowie)
					sedzia ! Zawodnik(imie._1)
				if(imie._2 == listaStartowa.length -1)
					context.become(NowyRanking(ranking, sedziowie.length))	
			}

			def NowyRanking(ranking: Ranking, lastN: Int): Receive = {
				case Ocena(zawodnik, wdziek, spryt) => {
					println(f"\n\n${sender().path.name} ocenil ${zawodnik.naz}: wdziek na ${wdziek} spryt na ${spryt}\n")
					var nowyRanking = Ranking(ranking.oceny ::: List(Ocena(zawodnik, wdziek, spryt)))
					context.become(NowyRanking(nowyRanking, lastN))
					nowyRanking.drukuj()
					if(ranking.oceny.count(x => listaStartowa.last._1 == x.z.naz) >= lastN){
						println("Stopping system");
						system.stop(self)
						system.terminate
					}
				}
			}
			
			def WybierzSkladSedziowski() = {
				val ile = random.nextInt(liczbaSedziow -1) +2
				val combin = skladSedziowski.combinations(ile).toList
				val ktory = random.nextInt(combin.length +1)
				combin(ktory)
			}
		})
    }
}
