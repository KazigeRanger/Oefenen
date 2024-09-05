from pyfiglet import Figlet
import sys

# Get the variable value from the command-line arguments
if len(sys.argv) == 1 or len(sys.argv) >= 4:
    print("Usage: fig <text> <font>")
    sys.exit(1)

string = sys.argv[1]

if len(sys.argv) == 3:
    setFont = sys.argv[2]
else:
    setFont = 'standard'

# Create a Figlet instance with a chosen font
figlet = Figlet(font=setFont)  # Replace 'script' with a font you like

# Generate text in the chosen font
text = figlet.renderText(string)
print(text)