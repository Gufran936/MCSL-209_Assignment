// Session – 1(3 hours) and Session-2 (3 hours) : Arrays

// Q2. Write a program in `C’ Language to accept 10 strings as input and print them in
// lexicographic order
// Input: 10 strings (use array of strings)
// Output: 10 input strings in lexicographic order

#include <stdio.h>
#include <string.h>

int main()
{
    char str[10][50], temp[50];
    int i, j;

    // Accept 10 strings from the user
    printf("Enter 10 strings:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%s", str[i]);
    }

    // Sort the strings using Bubble Sort in lexicographic (alphabetical) order
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    // Print the sorted strings
    printf("\nStrings in lexicographic order:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}