# Import get_int from cs50
from cs50 import get_int

# Invokes an infinite loop
while True:
    # Declare variable to get integer input from user
    height = get_int('Height: ')

    # Check if the input is between 0 and 9, break to proceed if true
    if height > 0 and height <= 8:
        break

if height > 0 and height <= 8:

    # Declare a column variable
    i = 1

    # Loop for each row
    for i in range(height):

        # Loop for blanks in each column
        for blanks in range(height-i-1):
            print(' ', end='')

        # Loop for blocks in each column
        for blocks in range(i+1):
            print('#', end='')

        # Next line to separate the rows
        print('\n', end='')