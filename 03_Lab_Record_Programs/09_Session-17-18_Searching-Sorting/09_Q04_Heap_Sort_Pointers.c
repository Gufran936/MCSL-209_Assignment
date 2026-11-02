// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q4. Write a program in ‘C’ language to implement Heap sort using pointers.

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function to swap two elements using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i using pointer arithmetic
void heapify(int *arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && *(arr + left) > *(arr + largest))
        largest = left;

    // If right child is larger than largest so far
    if (right < n && *(arr + right) > *(arr + largest))
        largest = right;

    // If largest is not root, swap and continue heapifying the affected sub-tree
    if (largest != i)
    {
        swap(arr + i, arr + largest);
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort using pointers
void heapSort(int *arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr, arr + i);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    printf("--- Heap Sort Using Pointers ---\n");
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

    // Perform Heap Sort
    heapSort(arr, n);

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