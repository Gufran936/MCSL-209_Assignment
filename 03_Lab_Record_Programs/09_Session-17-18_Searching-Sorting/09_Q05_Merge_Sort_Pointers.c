// Session-17 (3 hours) and Session-18 (3 hours) : Searching and Sorting

// Q5. Write a program in ‘C’ language to implement 2-way Merge sort using pointers.

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Function to merge two subarrays using pointer arithmetic
void merge(int *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays dynamically
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[] using pointers
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (*(L + i) <= *(R + j))
        {
            *(arr + k) = *(L + i);
            i++;
        }
        else
        {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        *(arr + k) = *(L + i);
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        *(arr + k) = *(R + j);
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}

// Function to implement 2-way merge sort using pointers
void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;

    printf("--- 2-Way Merge Sort Using Pointers ---\n");
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the main array
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

    // Perform Merge Sort
    mergeSort(arr, 0, n - 1);

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