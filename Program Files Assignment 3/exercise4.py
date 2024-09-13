# Shyam Venkatesan
# Used with command line interpreter, input values (lambda formula used for the function), writes a results table to the selected file or table.dat using user specifications

import sys # Sys imported for argv

# The write_table_to_file writes the results table to the file using all the user inputs
def write_table_to_file(f, xmin, xmax, nx, ymin, ymax, ny, width, decimals, filename):
    if decimals == 'None': # If the decimal choice is none, the variable is set to 0
        decimals = 0
    # The step sizes for x and y are calculated
    stepX = (xmax - xmin) / nx
    stepY = (ymax - ymin) / ny

    # file variable opens the filename file in write mode
    file = open(filename, 'w')

    # Iterates through the step size of y
    for j in range(int(stepY) + 1):
        # Finds each y value
        y = ymax - j * ny
        # Writes y value to the file with proper format
        file.write(f"{y:>{width}.{decimals}g}")
        # Iterates through the step size of x
        for i in range(int(stepX) + 1):
            x = xmin + i * nx # Finds each x value
            # Writes function result of x, y to the file with proper format
            file.write(f"{f(x, y):>{width}.{decimals}g}")
        file.write('\n') # Prints a new line

    file.write('\n') # Prints a new line
    file.write(f"{width*' ':>{width}}") # Prints width formatting before x values are printed
    # Iterates through the step size of x
    for i in range(int(stepX) + 1):
        x = xmin + i * nx # Finds each x value
        # Writes function result of x, y to the file with proper format
        file.write(f"{x:>{width}.{decimals}g}")
    file.close(); # Closes the file

def main():
    # Formula evaluates the lambda function
    formula = eval(sys.argv[1])
    # The following store their respective sys.argv values as floats
    xmin = float(sys.argv[2])
    xmax = float(sys.argv[3])
    nx = float(sys.argv[4])
    ymin = float(sys.argv[5])
    ymax = float(sys.argv[6])
    ny = float(sys.argv[7])
    # The following are optional values with defaults
    if(len(sys.argv) > 8):
        width = int(sys.argv[8])
    else:
        width = 10 # width set to 10 by default
    if(len(sys.argv) > 9):
            # Checks if decimals input is None or an actual value, and sets it as such
            if sys.argv[9] == 'None':
                decimals = 'None'
            else:
                decimals = int(sys.argv[9]) 
    else:
        decimals = 'None'    # decimals set to None by default
    if(len(sys.argv) > 10):
        filename = sys.argv[10]
    else:
        filename = 'table.dat' # filename set to table.dat by default

    # Calls write_table_to_file using input variables
    write_table_to_file(formula, xmin, xmax, nx, ymin, ymax, ny, width, decimals, filename)

# Call to main function for program to work
main()