name := "Zawody"
version := "1.0"

scalaVersion := "2.11.7"
scalacOptions := Seq("-unchecked", "-deprecation", "-encoding", "utf8")


libraryDependencies ++= {
    val akkaV = "2.4.1"
    Seq(
        "com.typesafe.akka" %% "akka-actor" % akkaV
    )
}

Revolver.settings
