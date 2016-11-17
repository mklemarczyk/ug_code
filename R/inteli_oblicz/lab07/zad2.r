setwd("C:\\Users\\mklemarczyk\\Desktop\\inteligencja\\lab07")

dirty.iris <- read.csv("dirty_iris.csv", header=TRUE, sep=",")

# Wyszukujemy tylko poprawne rekordy (bez NaN)
iris <- subset(dirty.iris, (is.finite(Sepal.Length) & is.finite(Sepal.Width) & is.finite(Petal.Length) & is.finite(Petal.Width)))
nrow(iris)

#install.packages("editrules")
library(editrules)

# Filtrujemy irysy warunkiem
E <- editset(c("Sepal.Length <= 30"))
E

# Znajdujemy niepasujace do filtra
ve <- violatedEdits(E, dirty.iris)
ve

summary(ve)
plot(ve)

# Nowy filter

E <- editset(expression(
    Species %in% c("setosa", "versicolor", "virginica"),
    Sepal.Length > 0,
    Sepal.Width > 0,
    Petal.Length > 0,
    Petal.Width > 0,
    Petal.Length > Petal.Width * 2,
    Sepal.Length > Petal.Length
))

# Znajdujemy niepasujace do filtra
ve <- violatedEdits(E, dirty.iris)
ve

summary(ve)
plot(ve)
