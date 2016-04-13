// src/main/scala/Prog.scala

// How to run:
// cd cw2
// sbt
// reStart

object Prog {
	import akka.actor._

	case class Init(first: ActorRef, n: Int)
	case class Message(msg: String, k: Int)
	
	class Friend extends Actor {
		var child : ActorRef = null
		var i : Int = 0
		def receive = {
			case Init(first, n) => {
				if(n > 0){
					i = n
					child = context.actorOf(Props[Friend])
					child ! Init(first, n-1)
				}else{
					child = first
				}
			}
			case Message(msg, k) => {
				//print("aktor ")
				//print(i)
				//print(" otrzymal ")
				//print(msg)
				//println(k)
				child ! Message(msg, k+1)
			}
		}
	}
	
	def main(args: Array[String]) : Unit = {
		println("Symulacja gry w gluchy telefon")
		var system = ActorSystem("system")
		var f1 = system.actorOf(Props[Friend], "first")
		var n = 100
		f1 ! Init(f1, n-1)
		f1 ! Message("cos",0)
	}
}
