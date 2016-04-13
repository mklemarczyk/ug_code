// src/main/scala/Prog.scala

// How to run:
// cd cw1
// sbt
// reStart

object Prog {
	import akka.actor._
	
	case class Ping()
	case class Pong()
	case class Init(aref: ActorRef)
	
	class Friend extends Actor {
		def receive = {
			case Init(aref) => aref ! Ping
			case Ping => {
				println("ping..")
				sender() ! Pong
			}
			case Pong => {
				println("pong...")
				sender() ! Ping
			}
		}
	}
	
	def main(args: Array[String]) : Unit = {
		println("Symulacja gry w ping ponga")
		var system = ActorSystem("system")
		var f1 = system.actorOf(Props[Friend], "f1")
		var f2 = system.actorOf(Props[Friend], "f2")
		f1 ! Init(f2)
	}
}
