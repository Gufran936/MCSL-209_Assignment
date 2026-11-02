// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q6. Write a program in ‘C’ language to implement Bubble sort using pointers.

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function to swap two elements using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement Bubble sort using pointers
void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            // Compare adjacent elements using pointer arithmetic
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(arr + j, arr + j + 1);
                swapped = 1;
            }
        }
        // If no two elements were swapped in the inner loop, the array is sorted
        if (swapped == 0)
        {
            break;
        }
    }
}

int main()
{
    int n;

    printf("--- Bubble Sort Using Pointers ---\n");
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i); // Using pointer notation for input
    }

    printf("\nOriginal Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Perform Bubble Sort
    bubbleSort(arr, n);

    printf("\nSorted Array (Ascending Order):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}