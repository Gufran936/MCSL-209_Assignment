// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q1. Write a program in ‘C’ language to implement linear search using pointers.

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function to implement linear search using pointers
int *linearSearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        // Using pointer arithmetic to check array elements
        if (*(arr + i) == key)
        {
            return (arr + i); // Return the pointer to the matched element
        }
    }
    return NULL; // Return NULL if the element is not found
}

int main()
{
    int n, key;

    printf("--- Linear Search Using Pointers ---\n");
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array to ensure full C standard compatibility
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i); // Passing base address + i using pointer notation
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call linear search function
    int *result = linearSearch(arr, n, key);

    if (result != NULL)
    {
        printf("\nElement %d FOUND at memory address %p (Index: %ld).\n",
               key, (void *)result, (result - arr));
    }
    else
    {
        printf("\nElement %d NOT found in the array.\n", key);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}