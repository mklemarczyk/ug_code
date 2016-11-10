setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab05")

iris.original = read.csv("diabetes.csv")

normalize <- function(x) {
	num <- x - min(x)
	denom <- max(x) - min(x)
	return (num/denom)
}

iris.numeric = iris.original[1:8]
#iris.preproc = scale(log(iris.numeric))
iris.preproc <- as.data.frame(lapply(iris[1:8], normalize))
iris.pca = prcomp(iris.preproc)
iris.pca.data = predict(iris.pca)

plot(iris.pca.data[,1], iris.pca.data[,2], xlab='PC1', ylab='PC2')
points(iris.pca.data[as.integer(rownames(subset(iris.original, class=='tested_positive'))),1], iris.pca.data[as.integer(rownames(subset(iris.original, class=='tested_positive'))),2], pch=16, col="red")
points(iris.pca.data[as.integer(rownames(subset(iris.original, class=='tested_negative'))),1], iris.pca.data[as.integer(rownames(subset(iris.original, class=='tested_negative'))),2], pch=16, col="green")
legend("topleft", c("Tak","Nie"), col = c("red","green"), pch = 1, title = "Legenda")
