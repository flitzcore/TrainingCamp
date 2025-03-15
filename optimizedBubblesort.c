#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort_by_area(int *arr, int n)
{
    /**
     * Sort an array a of the length n
     */

    int lastSortedIndex = n - 1;
    for (int i = 0; i < n; i++)
    {
        int isSorted = 1;
        int currentSortedIndex = -1;
        for (int j = 0; j < lastSortedIndex; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
                currentSortedIndex = j;
            }
        }
        if (isSorted)
        {
            return;
        }
        lastSortedIndex = currentSortedIndex;
    }
}
void sort_by_area_reverse(int *arr, int n)
{
    /**
     * Sort an array a of the length n
     */

    int lastSortedIndex = -1;
    for (int i = 0; i < n; i++)
    {
        int isSorted = 1;
        int currentSortedIndex = n + 1;
        for (int j = n - 1; j > lastSortedIndex; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                isSorted = 0;
                currentSortedIndex = j;
            }
        }
        if (isSorted)
        {
            return;
        }
        lastSortedIndex = currentSortedIndex;
    }
}
int main()
{
    int n = 10, arr[] = {0, 3, 2, 5, 4, 6, 1, 7, 9, 8};
    sort_by_area(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}