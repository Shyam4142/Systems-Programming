# Shyam Venkatesan
# Used with command line interpreter, takes file input, graphs a plot for density-temp data

import sys # Sys imported for argv
import matplotlib.pyplot as plot # pyplot imported as plot for plotting points

# The read_density_data function to read the file data from file_name file and put data in arrays temperatures, densities
def read_density_data(file_name):
    # Empty temperatures and densities arrays
    temperatures = []
    densities = []

    # file variable opens the file_name file in read mode
    file = open(file_name, 'r')
    # variable line reads a line from the file
    line = file.readline()
    # while the line is not null
    while line:
        # If the first letter of line is # (comment) or strip is empty string (empty line)
        if line[0] == ('#') or line.strip() == '':
            line = file.readline() # Reads next line
            continue # Continues loop
        # Maps each split token from the line into temp and density in float form
        temp, density = map(float, line.split()) 
        # Appends temp and density values to the respective arrays
        temperatures.append(temp)
        densities.append(density)
        line = file.readline() # Reads next line

    # Returns the filled temperatures and densities arrays
    return temperatures, densities

def main():
    # file_name variable holds the second command line input (file name argument)
    file_name = sys.argv[1] # Uses argv array

    # temperatures and densities hold return values of read_density_data call
    temperatures, densities = read_density_data(file_name)

    plot.scatter(temperatures, densities) # Scatter plot of temperatures and densities
    plot.xlabel('Temperature (Celsius)') # X-axis labeled as Temperature (Celsius)
    plot.ylabel('Density (kg/m^3)') # Y-axis labeled as Density (kg/m^3)
    plot.title('Density vs Temperature') # Title labeled as Density vs Temperature
    plot.show() # Shows the plot in GUI form

# Call to main function for program to work
main()