setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab04")

#1a
iris.original = read.csv("iris.csv")

#1b
cor(iris.original$sepallength, iris.original$sepalwidth, method = "pearson")
#-0.1093692
cor(iris.original$sepallength, iris.original$petallength, method = "pearson")
# 0.8717542
cor(iris.original$sepallength, iris.original$petalwidth, method = "pearson")
# 0.8179536
cor(iris.original$sepalwidth, iris.original$petallength, method = "pearson")
#-0.4205161
cor(iris.original$sepalwidth, iris.original$petalwidth, method = "pearson")
#-0.3565441
cor(iris.original$petallength, iris.original$petalwidth, method = "pearson")
# 0.9627571

#2abc
iris.numeric = iris.original[1:4]
iris.preproc = scale(log(iris.numeric))

#3a
iris.pca = prcomp(iris.preproc)

#3e
iris.pca.data = predict(iris.pca)

#iris.original[(dane[,5] == "Iris-virginica")]

#4
plot(iris.pca.data[,1], iris.pca.data[,2], xlab='PC1', ylab='PC2')
#ir1 = rownames(iris.original[(iris.original$class == "Iris-setosa"),])
points(iris.pca.data[1:50,1], iris.pca.data[1:50,2], pch=16, col="red")
#ir2 = rownames(iris.original[(iris.original$class == "Iris-versicolor"),])
points(iris.pca.data[51:100,1], iris.pca.data[51:100,2], pch=16, col="green")
#ir3 = rownames(iris.original[(iris.original$class == "Iris-virginica"),])
points(iris.pca.data[101:150,1], iris.pca.data[101:150,2], pch=16, col="blue")
legend("topleft", c("Iris-setosa","Iris-versicolor","Iris-virginica"), col = c("red","green","blue"), pch = 1, title = "Legenda")

#5
plotIris <- function(SeplLength,SepalWidth,PetalLength,PetalWidth){
	iris.original = read.csv("iris.csv")

	iris.numeric = iris.original[1:4]
	iris.numeric[151,] <- c(SeplLength, SepalWidth, PetalLength, PetalWidth)
	iris.preproc = scale(log(iris.numeric))
	iris.pca = prcomp(iris.preproc)
	iris.pca.data = predict(iris.pca)

	plot(iris.pca.data[,1], iris.pca.data[,2], xlab='PC1', ylab='PC2')
	points(iris.pca.data[1:50,1], iris.pca.data[1:50,2], pch=16, col="red")
	points(iris.pca.data[51:100,1], iris.pca.data[51:100,2], pch=16, col="green")
	points(iris.pca.data[101:150,1], iris.pca.data[101:150,2], pch=16, col="blue")
	points(iris.pca.data[151,1], iris.pca.data[151,2], pch=16, col="orange")
	legend("topleft", c("Iris-setosa","Iris-versicolor","Iris-virginica"), col = c("red","green","blue"), pch = 1, title = "Legenda")
};

