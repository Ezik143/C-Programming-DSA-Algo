#include <stdio.h>
#include <stdlib.h>
void print(int *number, int size);
void merge_sort(int *number, int size);
void merge_sort_recursion(int *number, int left, int right);
void merge_sorted_arrays(int *number,int left,int midpoint,int right);

int main()
{
    int numbers[6] = {7, 5, 4, 1, 2, 3};
    int size = sizeof(numbers) / sizeof(int);
    print(numbers, size);
    merge_sort(numbers, size);
    print(numbers, size);
    return 0;
}

void merge_sort(int *number, int size)
{
    merge_sort_recursion(number, 0,  size - 1 );
}

void merge_sort_recursion(int *number, int left, int right)
{
    if( left >= right) return;
    int midpoint =  left + (right - left) / 2;
    merge_sort_recursion(number, left, midpoint);
    merge_sort_recursion(number, midpoint + 1, right);


    merge_sorted_arrays(number, left, midpoint, right);
}

void merge_sorted_arrays(int *number,int left,int midpoint,int right)
{
    int left_size = midpoint - left + 1;
    int right_size = right - midpoint;

    int *temp_left = (int *)malloc(sizeof(int) * left_size);
    int *temp_right = (int *)malloc(sizeof(int) * right_size);

    
    for(int i = 0; i < left_size; i++){
         *(temp_left + i) = number[left + i];
    }
    for(int i = 0; i < right_size; i++){
        *(temp_right + i) = number[midpoint + 1 + i];
    }

    int i,j,k;

    for(i = 0, j = 0, k = left; k <= right; k++){
        if ((i < left_size) && ((j >= right_size) || temp_left[i] <= temp_right[j]))
        {
            *(number + k) = temp_left[i];
            i++;
        }
        else{
            *(number + k) = temp_right[j];
            j++;
        }
    }
    free(temp_left);
    free(temp_right);
}

void print(int *number, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(number + i));
    }
    printf("\n");
}