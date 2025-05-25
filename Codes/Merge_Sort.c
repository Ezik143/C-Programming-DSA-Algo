#include <stdio.h>

void Insert_Sort(int *number, int size);
void print(int *numbers, int size);

int main()
{
    int numbers[] = {2, 5, 6, 7, 1, 8, 3};
    int size = sizeof(numbers) / sizeof(int);
    print(numbers, size);
    Insert_Sort(numbers, size);
    print(numbers, size);
    return 0;
}

void Insert_Sort(int *number, int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = *(number + i);
        int j = i - 1;
        while (j >= 0 && *(number + j) > key)
        {
            *(number + j + 1) = *(number + j); 
            j = j - 1;
        }
        *(number + j + 1) = key;
    }
}

void print(int *numbers, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(numbers + i));
    }
    printf("\n");
}