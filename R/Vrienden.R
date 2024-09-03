library(dplyr)

myDataFrame = data.frame(name = c("Renger", "Manouk", "Thomas", "Siebrand", "Loek", "Jamie", "Jelle Z"),
                         age = c(16,17,16,16,17,17,16),
                         friend = c(NA, FALSE, TRUE, TRUE, FALSE, FALSE, TRUE))

colnames(myDataFrame) <- c("Name", "Age", "Friend")

myDataFrame$Alive <- TRUE
myDataFrame <- rbind(myDataFrame, c("Ebbo", 55, TRUE, TRUE))

myDataFrame$Stage <- "YOUNG"
myDataFrame[which(myDataFrame$Age > 30), 5] <- "OLD"

myName <- myDataFrame[1,1]
myFriends <- myDataFrame[which(myDataFrame$Friend == TRUE), 1]
print(myDataFrame)
# print(myName)
# print(myFriends)

