// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q2. Write a program in ‘C’ language to implement binary search using pointers.

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function to implement binary search using pointers
int *binarySearch(int *arr, int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int *midPtr = arr + mid; // Pointer to the middle element

        if (*midPtr == key)
        {
            return midPtr; // Return pointer to the found element
        }
        else if (*midPtr < key)
        {
            low = mid + 1; // Search in the right half
        }
        else
        {
            high = mid - 1; // Search in the left half
        }
    }
    return NULL; // Return NULL if not found
}

int main()
{
    int n, key;

    printf("--- Binary Search Using Pointers ---\n");
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements in sorted order (ascending):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Call binary search function
    int *result = binarySearch(arr, n, key);

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