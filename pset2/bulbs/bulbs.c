#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    //Prompt user for input
    string message = get_string("Message:");

    //Loop through each char in the message using for loop
    for (int i = 0; i < strlen(message); i++)
    {
        //Get the ascii value for char
        int ascii = message[i];

        //Create an empty array
        int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};

        //Create a variable
        int j = 0;

        //While condition to check ascii > 0
        while (ascii > 0)

        {
            //To store the remainder of ascii value / 2 in the indexes of the empty array
            binary[j] = ascii % 2;

            //To update the value of ascii as the quotient of ascii value / 2
            ascii = ascii / 2;

            //To move to the next index
            j++;
        }

        //To move throught the indexes of the binary array in reverse order
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)

        {
            //To print the values of 0's and 1's using print_bulb function
            print_bulb(binary[k]);
        }

        //To start from next line
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}