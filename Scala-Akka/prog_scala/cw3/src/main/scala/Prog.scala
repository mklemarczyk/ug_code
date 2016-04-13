// src/main/scala/Prog.scala

// How to run:
// cd cw3
// sbt
// reStart

object Prog {
	import akka.actor._

	case class Liczba(n: Int)
	case object Dajliczby
	case class Dajliczby(s1: List[Int])
	case class SwieteLiczby(ss: List[Int])
	
	class Liczbozaur extends Actor {
		def swietaLiczbazDzieckiem(swieta: Int, dziecko: ActorRef): Receive = {
			case Liczba(n) => {
				if((n % swieta) > 0) {
					dziecko ! Liczba(n)
				}
			}
			case SwieteLiczby(liczby) => {
				context.parent ! SwieteLiczby(List(swieta) ::: liczby)
			}
			case Dajliczby => {
				dziecko ! Dajliczby
			}
		}
		def swietaLiczba(swieta: Int): Receive = {
			case Liczba(n) => {
				if((n % swieta) > 0) {
					println("Stworzono dziecko")
					val dziecko = context.actorOf(Props[Liczbozaur])
					dziecko ! Liczba(n)
					context.become(swietaLiczbazDzieckiem(swieta, dziecko))
				}
			}
			case Dajliczby => {
				sender() ! SwieteLiczby(List(swieta))
			}
		}
		def receive: Receive = {
			case Liczba(n) => {
				println("Zapisano liczbe " + n)
				context.become(swietaLiczba(n))
			}
		}
	}
	
	def main(args: Array[String]) : Unit = {
		import akka.actor.ActorDSL._
		println("System liczenia")
		val system = ActorSystem("system")
		val N = 200
		actor(system, "main")(new Act {
			var root = system.actorOf(Props[Liczbozaur], "pierwszy")
			for(k <- 2 to N){
				root ! Liczba(k)
			}
			root ! Dajliczby
			become {
				case SwieteLiczby(ss) => println(ss)
			}
		})
	}
}
