#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Add the functions's prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

//Initialize variables
int letters = 0;
int words = 1;
int sentences = 0;

int main(void)
{
    //Take user input
    string text = get_string("Text:");

    //Call function with variable text as an argument
    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    //printf("%i\n",letters);
    //printf("%i\n",words);
    //printf("%i\n",sentences);

    //Coleman-Liau Index Calculation
    float cal = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;

    //Round off to get the index in int
    int index = round(cal);

    //Print grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//Function to count letters
int count_letters(string text)
{
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//Function to count words
int count_words(string text)
{
    int n = strlen(text);
    for (int i = 0; i <= n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

//Function to count sentences
int count_sentences(string text)
{
    int n = strlen(text);
    for (int i = 0; i <= n; i++)
    {
        if ((text[i]) == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}