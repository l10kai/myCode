name <- c("李明", "张聪", "王建")
class <- c("一班", "二班", "三班")
age<- c("30", "35", "28")
height = c("180", "162", "175")

df <- data.frame(name, class, age, height)

df

a <- list(name = "张三", class = "二班", age = "26", height = "177")

df = rbind(df, as.data.frame(a)) 

df

num <- c("0001", "0002", "0003", "0004")

df <- cbind(df, as.data.frame(num))

df

df[2, 3]

max(age)

df$height <- as.numeric(df$height)

average_height <- mean(df$height)

average_height 

students_class_1 <- subset(df, class == "一班")

students_class_1
