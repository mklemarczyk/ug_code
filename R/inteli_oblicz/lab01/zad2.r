setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab01")
dane = read.csv("osoby.csv")

place = round(abs(rnorm(length(dane[,1])))*3000+2000,2)
dane[,5] = place
names(dane)[5] <- "wyplata"

wiersz = data.frame("Jan", "Kowalski", "m", 30, round(abs(rnorm(1))*3000+2000,2))
names(wiersz) <- names(dane)
dane = rbind(dane, wiersz)

#Srednia
srednia = mean(dane$wyplata)
#Min
minumum = min(dane$wyplata)
#Max
maksimum = max(dane$wyplata)
#Odchylenie standardowe
odchylenie = sd(dane$wyplata)

stand <- function(x) { (x - srednia) / odchylenie }
norm <- function(x) { (x - minumum) / (maksimum - minumum) }

standaryzowane = stand(dane$wyplata)
dane[["standaryzowane"]] = standaryzowane

normalizowane = norm(dane$wyplata)
dane[["normalizowane"]] = normalizowane

#Summary - wiek: 40.88
summary(dane)
