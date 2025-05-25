#include <stdio.h>
#include <stdbool.h>

int Bubble_Sort(int *numbers, int size);
void print(int *numbers, int size);

int main(){
    int numbers[5] = {5,4,3,2,1};
    int size = sizeof(numbers) / sizeof(int);
    Bubble_Sort(numbers, size);
    print(numbers, size);
    return 0;
}


void print(int *numbers, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(numbers + i));
    }
}


int Bubble_Sort(int *numbers, int size){
    int temp = 0;
    bool swapped = false;
    while(!swapped){
        for(int i = 0; i < size - 1; i++){
            for(int j = 0; j < size - i - 1; j++){
                if( *(numbers + j) > *(numbers + j + 1)){
                    int temp = *(numbers  + j);
                    *(numbers + j) = *(numbers + j + j);
                    *(numbers + j + 1) = temp;
                }
            }
        }
        swapped = true;
    }
    return 0;
}