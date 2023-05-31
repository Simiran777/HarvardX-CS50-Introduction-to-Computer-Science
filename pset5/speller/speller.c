// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Declare variables
unsigned int word_count;
unsigned int hash_value;
unsigned int length;
unsigned long len;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get hash value
    hash_value = hash(word);

    // Point cursor to the first node
    node *cursor = table[hash_value];

    while (cursor != 0)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // Setting the declared int to the value of the longest word length
    length = 45;

    // Calculate the length of the word
    len = strlen(word);

    // Return calculated value
    return len % length;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");

    // If null, return false
    if (file == NULL)
    {
        printf("Unable to open %s", dictionary);
        return false;
    }

    // Declare a variable word
    char word[LENGTH + 1];

    // Scan the dictionary for strings until EOF
    while (fscanf(file, "%s\n", word) != EOF)
    {
        // Allocate memory for the new node
        node *n = malloc(sizeof(node));

        // If null, return false
        if (n == NULL)
        {
            return false;
        }

        // Copy the word from dictionary into the new node
        strcpy(n->word, word);

        // Pass the word from hash function to get hash value
        hash_value = hash(word);

        // Set new pointer
        n->next = table[hash_value];

        // Set head to new pointer
        table[hash_value] = n;

        // Increment word count
        word_count++;
    }

    // Close the file
    fclose(file);

    // If dict is loaded, return true
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Return the size of the dictionary
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Move through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to first node
        node *cursor = table[i];

        while (cursor)
        {
            // Temporary variable to copy cursor
            node *tmp = cursor;

            // Move cursor to next node
            cursor = cursor->next;

            // Free temporary variable
            free(tmp);
        }
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}