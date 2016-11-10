# Instalacja (jednorazowo) i załadowanie biblioteki
# install.packages("genalg")
library("genalg")
setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab02")

# Dodawanie zbioru danych i limitu plecaka
dataset <- read.csv("labirynt.csv", header = FALSE)

startPos = c(2,2)
endPos = c(7,10)

fitnessPrint <- function(x) {
	myPos = startPos
	lastPos = myPos
	dlugosc = length(x) / 2
	for(i in 1:dlugosc){
		a = i*2 -1
		b = i*2
		if(x[a] == 0 && x[b] == 0){			# 00 G
			print("G")
		}else if(x[a] == 1 && x[b] == 0){	# 10 L
			print("L")
		}else if(x[a] == 0 && x[b] == 1){	# 01 P
			print("P")
		}else if(x[a] == 1 && x[b] == 1){	# 11 D
			print("D")
		}
		if(dataset[myPos[1], myPos[2]] == "X"){
			return(0)
		}else if(dataset[myPos[1], myPos[2]] == "#"){
			break
		}else{
			lastPos = myPos
		}
	}
}

# funkcji fitness
fitnessFunc <- function(x) {
	myPos = startPos
	lastPos = myPos
	dlugosc = length(x) / 2
	for(i in 1:dlugosc){
		a = i*2 -1
		b = i*2
		if(x[a] == 0 && x[b] == 0){			# 00 G
			myPos = myPos - c(1,0)
		}else if(x[a] == 1 && x[b] == 0){	# 10 L
			myPos = myPos - c(0,1)
		}else if(x[a] == 0 && x[b] == 1){	# 01 P
			myPos = myPos + c(0,1)
		}else if(x[a] == 1 && x[b] == 1){	# 11 D
			myPos = myPos + c(1,0)
		}
		print(myPos)
		if(dataset[myPos[1], myPos[2]] == "X"){
			return(0)
		}else if(dataset[myPos[1], myPos[2]] == "#"){
			break
		}else{
			lastPos = myPos
		}
	}
	print(myPos)
	di = myPos - endPos
	odleglosc = sqrt(di[1]*di[1]+di[2]*di[2])
	return(odleglosc)
}

# algorytm genetyczny
GAmodel <- rbga.bin(size = 176, popSize = 200, iters = 100, mutationChance = 0.01, elitism = T, evalFunc = fitnessFunc)
summary(GAmodel, echo=TRUE)
