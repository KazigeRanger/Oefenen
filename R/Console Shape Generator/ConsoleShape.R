library(magick)

letter_vector <- c("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z") # nolint: commas_linter, line_length_linter.

# Loop over every pixel of an image and check for brightness to determine what
# pixels the letter occupies. Determine the minimal and maximal x and y values
# that the letter occupies. Do this for every letter, then crop every letter to
# the size that the biggest letter occupies.

a_image <- image_read("./R/Console Shape Generator/Letter PNGs/a.png")
a_grey <- image_convert(a_image, colorspace = "gray")
a_data <- image_data(a_grey)
a_matrix <- as.numeric(a_data)
a_matrix <- matrix(a_matrix, nrow = dim(a_data)[1], ncol = dim(a_data)[2])
max_value <- max(a_matrix)
coords <- which(a_matrix > 0, arr.ind = TRUE)

image_write(a_grey, path = "./R/Console Shape Generator/Letter PNGs/a_grey.png")
print(coords)
