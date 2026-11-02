// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q3. Write a program in ‘C’ language to implement Quick sort using pointers.

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function to swap two elements using pointers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using pointer arithmetic
int partition(int *arr, int low, int high)
{
    int pivot = *(arr + high); // Pivot element
    int i = (low - 1);         // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (*(arr + j) <= pivot)
        {
            i++; // Increment index of smaller element
            swap(arr + i, arr + j);
        }
    }
    swap(arr + i + 1, arr + high);
    return (i + 1);
}

// Quick sort function using pointers
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    printf("--- Quick Sort Using Pointers ---\n");
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

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

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