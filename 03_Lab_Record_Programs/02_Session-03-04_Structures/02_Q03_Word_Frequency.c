// Session-3 (3 hours) and Session-4 (3 hours): Structures

// Q3. Write a program in ‘C’ language to accept a paragraph of text as input. Make a
// list of words and the number of occurrences of each word in the paragraph as
// output. As part of the processing, an array and structure should be created
// wherein each structure consists of two fields, namely, one for storing the word
// and the other for storing the number of occurrences of that word.

#include <stdio.h>
#include <string.h>

struct WordCount
{
    char word[50];
    int count;
};

int main()
{
    char paragraph[1000];
    struct WordCount words[100];
    int uniqueWords = 0;

    printf("Enter a paragraph of text:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Tokenize paragraph into words using delimiters (spaces, punctuation)
    char *token = strtok(paragraph, " \t\n.,;!?");

    while (token != NULL)
    {
        int found = 0;

        // Check if word already exists in our structure array
        for (int i = 0; i < uniqueWords; i++)
        {
            if (strcmp(words[i].word, token) == 0)
            {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If it's a new word, add it to the array
        if (!found)
        {
            strcpy(words[uniqueWords].word, token);
            words[uniqueWords].count = 1;
            uniqueWords++;
        }

        token = strtok(NULL, " \t\n.,;!?");
    }

    // Display the word occurrence list
    printf("\nWord Frequencies:\n");
    printf("Word\t\tCount\n");
    printf("---------------------\n");
    for (int i = 0; i < uniqueWords; i++)
    {
        printf("%-15s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}