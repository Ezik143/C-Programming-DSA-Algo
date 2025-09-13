#include <stdio.h>
#include <stdlib.h>

void merge_recursive(int list[], int L, int R);
void merge_sorted(int list[], int L, int midpoint, int R);
void merge_Sort(int list[], int length);

void print_array(int list[], int length)
{
    for (int i = 0; i < length ; i++)
    {
        printf("%d ", list[i]);
    }
    
}

int main()
{
    int list[] = {6, 5, 4, 8, 1, 2};
    int length = sizeof(list) / sizeof(int);
    merge_Sort(list, length);
    print_array(list, length);
    return 0;
}

void merge_Sort(int list[], int length)
{
    merge_recursive(list, 0, length - 1);
}

void merge_recursive(int list[], int L, int R)
{
    if (L < R)
    {
        int midpoint = L + (R - L) / 2;
        merge_recursive(list, L, midpoint);
        merge_recursive(list, midpoint + 1, R);
        merge_sorted(list, L, midpoint, R);
    }
}
void merge_sorted(int list[], int L, int midpoint, int R)
{
    int left_length = midpoint - L + 1;
    int right_length = R - midpoint;

    int *left_temp = (int *)malloc(left_length * sizeof(int));
    int *right_temp = (int *)malloc(right_length * sizeof(int));

    for (int i = 0; i < left_length; i++)
    {
        left_temp[i] = list[L + i];
    }
    for (int j = 0; j < right_length; j++)
    {
        right_temp[j] = list[midpoint + 1 + j];
    }
    int i, j, k;

    i = 0;
    j = 0;
    k = L;
    
    while (i < left_length || j < right_length)
    {
        if (i < left_length && (j >= right_length || left_temp[i] <= right_temp[j]))
        {
            list[k] = left_temp[i];
            i++;
        }
        else if (j < right_length)
        {
            list[k] = right_temp[j];
            j++;
        }
        k++;
    }
    free(left_temp);
    free(right_temp);
}