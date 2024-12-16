a <- rnorm(100)
plot(a)
print("我是异史君")


h <- c(1, 2, 3, 4, 5, 6)
M <- c("A", "B", "C", "D", "E", "F")
barplot(
    h,
    names.arg = M,
    xlab = "X",
    ylab = "Y",
    col = "#00c0c9",
    main = "Chart",
    border = "#fdcb6e"
)


C1 <- c(1, 2, 3, 4)
C2 <- c(1, 2, 3, 4)
C3 <- c(1, 2, 3, 4)
C4 <- c(1, 2, 3, 4)
C5 <- c(1, 2, 3, 4)
mydata_frame <- data.frame(C1, C2, C3, C4, C5)
View(mydata_frame)
