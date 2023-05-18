#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // To move through the columns of the image
    for (int i = 0; i < width; i++)
    {
        // To move through the rows of the image
        for (int j = 0; j < height; j++)
        {
            // To check if the current pixel is black
            if (image[i][j].rgbtRed == 0 & image[i][j].rgbtBlue == 0 & image[i][j].rgbtGreen == 0)
            {
                // To change the colour of the pixel
                image[i][j].rgbtRed = 125;
                image[i][j].rgbtBlue = 140;
                image[i][j].rgbtGreen = 45;
            }
        }
    }
}