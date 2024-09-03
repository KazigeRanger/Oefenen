library(dplyr)

newDataFrame <- data.frame(Vak = c("Nederlandse taal en literatuur", "Engelse taal en literatuur", "Latijn", "maatschappijleer", "lichamelijke opvoeding", "wiskunde B", "natuurkunde", "scheikunde", "onderzoek en ontwerpen", "filosofie"),
                            SE = c(8.2,7.8,6.4,7,7,8.9,8.0,7.9,6,7.6))

newDataFrameSummary <- newDataFrame %>%
mutate(Cum_Laude = case_when(
    SE >= 7.5 ~ TRUE,
    SE < 7.5 ~ FALSE
)) %>%
summarize(
    items = n(),
    maximum = max(SE),
    mean = mean(SE),
    minimum = min(SE)
)

cumLaudeVakken <- filter(newDataFrame, SE >= 7.5)
arrangedDataFrame <- arrange(newDataFrame, desc(SE))

print(newDataFrame)
print(newDataFrameSummary)
print(cumLaudeVakken)
print(arrangedDataFrame)
