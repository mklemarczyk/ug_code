setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab06")

#install.packages("party")
library("party")

iris <- read.csv("iris.csv")

set.seed(1234)

ind <- sample(2, nrow(iris), replace=TRUE, prob=c(0.70, 0.30))

iris.training <- iris[ind == 1, 1:5]
iris.test <- iris[ind == 2, 1:5]

str(iris)

iris_ctree <- ctree(class ~ sepallength + sepalwidth + petallength + petalwidth, data=iris.training)

print(iris_ctree)
plot(iris_ctree)

table(predict(iris_ctree, iris.test[,-5]), iris.test[,5])
