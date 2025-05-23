#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

//NA ALL DYNAMIC ARRAY

char ASK();

int main()
{
    int newsize = 0;
    int size = 0;
    printf("size:");
    scanf("%d", &size);
    int *arr = malloc(size * sizeof(int));
    printf("welcome to dynamic array\n");
    for (int i = 0; i < 5; i++)
    {
        printf("enter a number for %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    char option = ASK();
    if (option == 'Y')
    {
        printf("how many many:");
        scanf("%d", &newsize);
        int *temp = (int *)realloc(arr, newsize * sizeof(int));
        if (temp == NULL) {
            printf("Memory reallocation failed.\n");
            free(arr);
            return 1;
        }
        arr = temp;
    }
    else if (option == 'N')
    {
        printf("thank you for using this program\n");
        return 0;
    }
    for (int i = size ; i < size + newsize; i++)
    {
        printf("enter a number for %d:", i + 1);
        scanf("%d",&arr[i]);
    }

    printf("%d", sizeof(arr) / sizeof(int));
    printf("\n");

    for (int i = 0; i < size + newsize; i++)
    {
        printf("you entered:%d\n", arr[i]);
    }
    free(arr);
    return 0;
}

char ASK()
{
    char option = '\0';
    char upperOption;
    do
    {
        printf("would you like to add another numbers?(Y/N)\n");
        option = getch();
        upperOption = toupper(option);
    } while (upperOption != 'Y' && upperOption != 'N');
    return upperOption;
}