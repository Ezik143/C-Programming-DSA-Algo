#include <stdio.h>

void bubbleSort(int *list, int size);
void print(int *List, int size);

int main()
{
    int List[6] = {5, 3, 1, 2, 6, 8};
    int size = sizeof(List) / sizeof(int);
    bubbleSort(List, size);
    print(List, size);
    return 0;
}

void bubbleSort(int *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(list + j) > *(list + j + 1))
            {
                int temp = 0;
                temp = *(list + j + 1);
                *(list + j + 1) = *(list + j);
                *(list + j) = temp;
            }
        }
    }
}

void print(int *List, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(List + i));
    }
}