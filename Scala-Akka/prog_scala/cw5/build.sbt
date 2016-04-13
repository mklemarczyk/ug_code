name := "COs"
version := "0.1"
scalaVersion := "2.11.7"

scalacOptions := Seq(" -unchecked", " -deprecated", " -encoding", "utf8")

libraryDependencies ++= {
	val akkaV = "2.4.1"
	Seq(
		"com.typesafe.akka" %% "akka-actor" % akkaV
	)
}

Revolver.settings
