#include <stdio.h>
#include <stdio.h>

void merge_Sort(int list[], int size);
void merge_Recursion(int list[], int L, int R);
void merge_sorted_Recursion(int list[], int L, int mid, int R);

int main()
{
    int list[] = {6, 5, 3, 2, 1};
    int size = sizeof(list) / sizeof(int);
    merge_Sort(list, size);
    return 0;
}

void merge_Sort(int list[], int size)
{
    merge_Recursion(list, 0, size - 1);
}

void merge_Recursion(int list[], int L, int R)
{
    if (L < R)
    {
        int mid = L + (L - R) / 2;
        merge_Recusion(list, L, mid);
        merge_Recursion(list, mid + 1, R);
        merge_sorted_Recursion(list, L, mid, R);
    }
}

void merge_sorted_Recursion(int list[], int L, int mid, int R)
{
    int left_length = mid - L + 1;
    int right_length = R - mid;
    int *left_side = (int *)malloc(left_length * sizeof(int));
    int *right_side = (int *)malloc(right_length * sizeof(int));

    for (int i = 0; i < left_length; i++)
    {
        left_side[i] = list[L + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        right_side[i] = list[mid + 1 + i];
    }

    int i, j, k;
    for (i = 0, j = 0, k = 0; k < R; k++)
    {
        if (i < left_side && (j >= right_side ||  left_side[i] <= right_side[j]))
        {
            list[k] = left_side[i];
            i++;
        }
        else
        {
            list[k] = right_side[j];
            j++;
        }
    }
}