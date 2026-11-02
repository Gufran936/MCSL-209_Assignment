// Session – 1(3 hours) and Session-2 (3 hours) : Arrays

// Q3. Write a program in `C’ Language that accepts two strings S1 and S2 as input.
// The program should check if S2 is a substring of S1 or not. If S2 is a substring
// of S1, then the program should output the starting location and ending location
// of S2 in S1. If S2 appears more than once in S1, then the locations of all
// instances have to be given.

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    int i, j, l1, l2, found = 0;

    // Accept main string S1 and substring S2
    printf("Enter main string S1: ");
    scanf("%s", s1);

    printf("Enter substring S2: ");
    scanf("%s", s2);

    l1 = strlen(s1);
    l2 = strlen(s2);

    printf("\nResults:\n");

    // Loop to check for substring matches
    for (i = 0; i <= l1 - l2; i++)
    {
        for (j = 0; j < l2; j++)
        {
            if (s1[i + j] != s2[j])
            {
                break;
            }
        }
        // If all characters match
        if (j == l2)
        {
            found = 1;
            printf("Substring found! Starting index: %d, Ending index: %d\n", i, i + l2 - 1);
        }
    }

    if (!found)
    {
        printf("S2 is not a substring of S1.\n");
    }

    return 0;
}