stand <- function(x) { (x - mean(x)) / sd(x) }
norm <- function(x) { (x - min(x)) / (max(x) - min(x)) }
