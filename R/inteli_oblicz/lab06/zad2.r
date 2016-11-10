setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab06")

#install.packages("e1071")
library(e1071)

iris <- read.csv("iris.csv")

set.seed(1234)

ind <- sample(2, nrow(iris), replace=TRUE, prob=c(0.70, 0.30))

iris.training <- iris[ind == 1, 1:5]
iris.test <- iris[ind == 2, 1:5]

## Example with metric predictors:
data(iris)
m <- naiveBayes(class ~ ., data = iris.training)

m

table(predict(m, iris.test[,-5]), iris.test[,5])

