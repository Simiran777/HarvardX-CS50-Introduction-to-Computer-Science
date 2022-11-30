#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // A string to get name from user
    string name = get_string("What's your name? ");
    // Print hello, name
    printf("hello,%s\n", name);
}