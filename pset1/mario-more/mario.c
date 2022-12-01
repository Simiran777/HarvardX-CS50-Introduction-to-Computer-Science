#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variable for height
    int height;
    // Loop to keep asking height until 1<=height<=8
    do
    {
        height = get_int("Height of the pyramid? ");
    } while (height < 1 || height > 8);

    // Loop for i no of rows
    for (int i = 1; i <= height; i++)
    {
        // Loop for k no of spaces
        for (int k = height - 1; k >= i; k--)
        {
            printf(" ");
        }

        // Loop for j no of columns
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        // For the middle gap
        printf("  ");

        // Loop for left aligned hash pattern
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}