// src/main/scala/Prog.scala

// How to run:
// cd cw5
// sbt
// reStart

// src/main/scala/Primes.scala

object Prog {
	import akka.actor._

	def main(args: Array[String]): Unit = {
		val zadok = koduj("ALAMAKOTAIPSA", 
						  "TAJNY")
		println(zadok);
		println(dekoduj(new String(zadok.toArray), "TAJNY"));
	}

	def koduj(tekst: String, kod: String): IndexedSeq[Char] = {
		val aCode = 'A'.toInt
		val maxCode = 'Z'.toInt - aCode
		val n = tekst.length
		val kn = kod.length
		for { i <- 0 until tekst.length
		      x = teskt(i) - aCode
		      y = kod(i % kn) - aCode
		      z = (x + y) % maxCode
		} yield (z + aCode).toChar
	}

	def dekoduj(tekst: String, kod: String): String = {
		val aCode = 'A'.toInt
		val maxCode = 'Z'.toInt - aCode
		val kn = kod.length
		var i = 0;
		tekst.map(
			c => {
		        val x = c - aCode
		        val y = kod(i % kn) - aCode
		        val z = (x - y + maxCode) % maxCode
		        i = i+1
		        (z + aCode).toChar
			}
		)
	}
}
