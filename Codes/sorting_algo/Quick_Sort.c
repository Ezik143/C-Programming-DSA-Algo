#include <stdio.h>

void quicksort(int list[], int size);

void quicksort_recursion(int list[], int low, int high);

int partition(int list[], int low, int high);

void swap(int *x, int *y);

int main()
{
    int list[] = {
        4,
        5,
        6,
        7,
        8,
        9,
        1,
        3,
        5,
        7,
    };
    
    int size = sizeof(list) / sizeof(list[0]);
    
    quicksort(list, size);

    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int list[], int size)
{
    quicksort_recursion(list, 0, size - 1);
}

void quicksort_recursion(int list[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(list, low, high);
        quicksort_recursion(list, low, pivot - 1);
        quicksort_recursion(list, pivot + 1, high);
    }
}

int partition(int list[], int low, int high)
{
    int pivot_value = list[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (list[j] <= pivot_value)
        {
            swap(&list[i], &list[j]);
            i++;
        }
    }
    swap(&list[i], &list[high]);
    return i;
}