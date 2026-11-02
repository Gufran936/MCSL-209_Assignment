// Session-3 (3 hours) and Session-4 (3 hours): Structures

// Q2. Write a program in ‘C’ language to multiply two sparse matrices.

#include <stdio.h>

struct Element
{
    int row;
    int col;
    int val;
};

void createSparse(int mat[10][10], int r, int c, struct Element s[100])
{
    int k = 1;
    s[0].row = r;
    s[0].col = c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                s[k].row = i;
                s[k].col = j;
                s[k].val = mat[i][j];
                k++;
            }
        }
    }
    s[0].val = k - 1; // Total number of non-zero elements
}

void displaySparse(struct Element s[100])
{
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= s[0].val; i++)
    {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
    }
}

int main()
{
    int r1, c1, r2, c2;
    int matA[10][10], matB[10][10];
    struct Element s1[100], s2[100], s3[100];

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }

    if (c1 != r2)
    {
        printf("Matrix multiplication not possible! Columns of A must match Rows of B.\n");
        return 0;
    }

    createSparse(matA, r1, c1, s1);
    createSparse(matB, r2, c2, s2);

    // Standard sparse multiplication logic
    int k = 1;
    s3[0].row = r1;
    s3[0].col = c2;

    for (int i = 1; i <= s1[0].val; i++)
    {
        for (int j = 1; j <= s2[0].val; j++)
        {
            if (s1[i].col == s2[j].row)
            {
                int target_r = s1[i].row;
                int target_c = s2[j].col;
                int product_val = s1[i].val * s2[j].val;

                int found = 0;
                for (int m = 1; m < k; m++)
                {
                    if (s3[m].row == target_r && s3[m].col == target_c)
                    {
                        s3[m].val += product_val;
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    s3[k].row = target_r;
                    s3[k].col = target_c;
                    s3[k].val = product_val;
                    k++;
                }
            }
        }
    }
    s3[0].val = k - 1;

    printf("\nSparse Representation of Resultant Matrix (A x B):\n");
    displaySparse(s3);

    return 0;
}