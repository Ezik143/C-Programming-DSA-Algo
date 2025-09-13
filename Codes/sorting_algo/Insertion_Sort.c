#include <stdio.h>
#include <stdbool.h>

void insertion_sort(int list[], int size);

void print(int list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
}

int main()
{
    int list[] = {6, 5, 3, 2, 1};
    int size = sizeof(list) / sizeof(int);
    insertion_sort(list, size);
    print(list, size);
    return 0;
}

void insertion_sort(int list[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && list[j - 1] > list[j])
        {
            int temp = list[j - 1];
            list[j - 1] = list[j];
            list[j] = temp;
            j--;
        }
    }
}
