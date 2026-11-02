// Session – 1(3 hours) and Session-2 (3 hours) : Arrays

// Q1. Write a program in `C’ language that accepts two matrices as input and prints
// their product.
// Input: Two matrices A and B in two-dimensional arrays
// Output: Matrix `C’ which is result of A X B in the form of two dimensional array

#include <stdio.h>

int main()
{
    int r1, c1, r2, c2, i, j, k;
    int a[10][10], b[10][10], product[10][10];

    // Read rows and columns for first matrix
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Read rows and columns for second matrix
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible (Columns of first == Rows of second)
    while (c1 != r2)
    {
        printf("Error! Column of first matrix must equal row of second matrix.\n");
        printf("Enter rows and columns for first matrix: ");
        scanf("%d %d", &r1, &c1);
        printf("Enter rows and columns for second matrix: ");
        scanf("%d %d", &r2, &c2);
    }

    // Input elements of first matrix
    printf("Enter elements of matrix A:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input elements of second matrix
    printf("Enter elements of matrix B:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize product matrix elements to 0
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            product[i][j] = 0;
        }
    }

    // Multiply matrices a and b
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the resultant product matrix
    printf("\nResultant Matrix C (A X B):\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}