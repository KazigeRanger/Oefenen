library(ggplot2)

rapport2 <- data.frame(Vak = c("Nederlandse taal en literatuur","Engelse taal en literatuur","Latijn","maatschappijleer","lichamelijke opvoeding","wiskunde B","natuurkunde","scheikunde","onderzoek en ontwerpen","economie","filosofie"),
                        Gem1 = c(8.0,7.7,6.5,7.6,8.0,7.8,7.3,7.8,6.5,7.8,5.6),
                        WH1 = c(NA,"V","V",NA,"G","G","V","V","V","G","G"),
                        Gem2 = c(7.4,6.5,7.0,6.4,8.0,8.0,6.2,8.7,7.2,8.1,8.6),
                        WH2 = c("V","V","G",NA,"G","V","V","V","V","G","G"),
                        Gem_Eind = c(7.7,7.1,6.8,6.8,8.0,7.8,6.8,8.3,7.0,8.0,7.5),
                        Afgerond_Eind = c(8,7,7,7,8,8,7,8,7,8,8))

# print(rapport2)

plot <- ggplot(data = rapport2, aes(x = Gem_Eind, y = Gem1, color = as.factor(Vak), size = Gem_Eind)) + geom_point() + geom_abline(slope = 1, intercept = 0) + labs(x = "Eindgemiddelde", y = "Gemiddelde in periode 1", title = "Gemiddelde in periode 1 vs Eindgemiddelde")
# annotate("text", x = 30, y = 5, label="Alle punten die onder de lijn vallen zijn cijfers die ik heb opgehaald.")
print(plot)