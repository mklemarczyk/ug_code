// src/main/scala/Prog.scala

// How to run:
// cd cw3
// sbt
// reStart

// src/main/scala/Primes.scala

object Prog {
	import akka.actor._

	case class Num(n: Int)
	case object GetPrimes
	case class Primes(primes: List[Int])

	class MyActor extends Actor {

		def withNum(myNum: Int): Receive = {
			case Num(n) => if (n % myNum != 0) {
				// tworzymy potomka, wysyłamy do niego "n" i stajemy się withNumAndSlave
				val slave = context.actorOf(Props[MyActor], s"slave$n")
				slave ! Num(n)
				context.become(withNumAndSlave(myNum, slave))
			}
			case GetPrimes => sender() ! Primes(List(myNum))
		}

		def withNumAndSlave(myNum: Int, slave: ActorRef): Receive = {
			case Num(n) => if (n % myNum != 0) {
				// wysyłamy "n" do naszego potomka
				slave ! Num(n)
			}
			case GetPrimes => slave ! GetPrimes
			case Primes(primes) => context.parent ! Primes(myNum :: primes)
		}

		def receive: Receive = {
			case Num(n) => context.become(withNum(n))  
		}
	}

	def main(args: Array[String]): Unit = {
		import akka.actor.ActorDSL._
		val system = ActorSystem("system")
		val N = 200
		// Tworzymy "aktora programu głównego"
		actor(system, "main")(new Act {
			// wysyłamy do root liczby z listy List(2,3,4,5,..., N)
			val root = system.actorOf(Props[MyActor], "root")
			for (n <- 2 to N) root ! Num(n)
			// wysyłamy do root GetPrimes
			root ! GetPrimes
			become {
				case Primes(primes) => 
					println(s"Liczby pierwsze z przedziału [2..$N]:")
					for (p <- primes) println(p)
			}
		})
	}
}
