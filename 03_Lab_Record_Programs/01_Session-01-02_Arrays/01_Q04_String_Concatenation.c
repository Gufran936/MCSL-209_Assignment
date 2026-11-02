// Session – 1(3 hours) and Session-2 (3 hours) : Arrays

// Q4. Write a program to concatenate two strings S1 and S2.

#include <stdio.h>

int main()
{
    char s1[200], s2[100];
    int i = 0, j = 0;

    // Accept first string S1
    printf("Enter first string S1: ");
    scanf("%s", s1);

    // Accept second string S2
    printf("Enter second string S2: ");
    scanf("%s", s2);

    // Find the end of string S1
    while (s1[i] != '\0')
    {
        i++;
    }

    // Copy characters of S2 to the end of S1
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    // Null-terminate the final concatenated string
    s1[i] = '\0';

    // Display the concatenated result
    printf("Concatenated String (S1 + S2): %s\n", s1);

    return 0;
}