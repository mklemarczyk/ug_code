setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab05")

iris <- read.csv("iris.csv")

names(iris) <- c("Sepal.Length", "Sepal.Width", "Petal.Length", "Petal.Width", "Species")

table(iris$Species)

round(prop.table(table(iris$Species)) * 100, digits = 1)

summary(iris[c("Petal.Width", "Sepal.Width")])

normalize <- function(x) {
	num <- x - min(x)
	denom <- max(x) - min(x)
	return (num/denom)
}

iris_norm <- as.data.frame(lapply(iris[1:4], normalize))

summary(iris_norm)

set.seed(1234)

ind <- sample(2, nrow(iris), replace=TRUE, prob=c(0.67, 0.33))

iris.training <- iris[ind==1, 1:4]
iris.test <- iris[ind==2, 1:4]

iris.trainLabels <- iris[ind==1, 5]
iris.testLabels <- iris[ind==2, 5]

library(class)

iris_pred <- knn(train = iris.training, test = iris.test, cl = iris.trainLabels, k=3)

#install.packages("gmodels")
library(gmodels)

CrossTable(x = iris.testLabels, y = iris_pred, prop.chisq=FALSE)
