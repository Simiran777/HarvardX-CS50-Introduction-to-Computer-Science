#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // For rows of the image
    for (int i = 0; i < height; i++)
    {
        // For column of the image
        for (int j = 0; j < width; j++)
        {
            // For computing grayscale value
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int gray = round((Red + Green + Blue) / 3);
            // For storing grayscale value
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // For rows of the image
    for (int i = 0; i < height; i++)
    {
        // For columns of the image
        for (int j = 0; j < width; j++)
        {
            // For computing sepia values
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // For storing sepia values of red, green and blue
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

            // For capping the values at 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // For updating the color
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // For rows of the image
    for (int i = 0; i < height; i++)
    {
        // For columns of the image
        for (int j = 0; j < width / 2; j++)
        {
            // Creating temp variable to swap the pixel values
            RGBTRIPLE temp = image[i][j];

            // To swap the pixel values
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Creating a temporary image to store the actual image
    RGBTRIPLE temp[height][width];

    // For rows of the image
    for (int i = 0; i < height; i++)
    {
        // For columns of the image
        for (int j = 0; j < width; j++)
        {
            // Stores the image in the temporary image
            temp[i][j] = image[i][j];
        }
    }

    // For rows of the image
    for (int i = 0; i < height; i++)
    {
        // For columns of the image
        for (int j = 0; j < width; j++)
        {
            // Creating variables to store the average values
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;

            // To keep a count of the number of pixels
            float count = 0;

            // For moving up and down the current row
            for (int row = i - 1; row <= i + 1; row++)
            {
                // For moving left and right the current column
                for (int column = j - 1; column <= j + 1; column++)
                {
                    // For skipping the pixels that are out of the image
                    if (row < 0 || row > (height - 1) || column < 0 || column > (width - 1))
                    {
                        continue;
                    }

                    // For totalling the red, green and blue values
                    totalRed += image[row][column].rgbtRed;
                    totalGreen += image[row][column].rgbtGreen;
                    totalBlue += image[row][column].rgbtBlue;

                    count++;
                }

                // For computing the average values
                temp[i][j].rgbtRed = round(totalRed / count);
                temp[i][j].rgbtGreen = round(totalGreen / count);
                temp[i][j].rgbtBlue = round(totalBlue / count);
            }
        }
    }
    // For rows of the image
    for (int i = 0; i < height; i++)
    {
        // For columns of the image
        for (int j = 0; j < width; j++)
        {
            // For storing the image in the original image
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}