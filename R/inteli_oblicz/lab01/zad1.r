setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab01")
dane = read.csv("osoby.csv")
#Wyświetl same imiona
dane$imiona
#Wyświetl tylko dane kobiet
dane[dane[,3] == "k",]
#Wyświetl dane mężczyzn starszych niż 50 lat i zapisz je w osobnym pliku osoby2.csv
men = dane[(dane[,4] > 50) & (dane[,3] == "m"),]
write.csv(men, "osoby2.csv", rownames=FALSE)
