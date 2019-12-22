#include <stdio.h>
#define SIZE 50

void shift_element (int* arr, int i){
    while(i>0){
        *(arr+i) = *(arr+i-1);
        i--;
    }
}

void insertion_sort(int* arr, int len){
    int temp, i, count;
    for(int j=1; j<len; j++){
        count = 0;
        temp = *(arr+j);
        i = j-1;
        while(i>=0 && *(arr+i)>temp){
            count++;
            i--;
        }
        if(count>0){
            shift_element(arr+i+1, count);
            *(arr+i+1) = temp;
        }
    }
}

int main() {
    int array[SIZE]; //init -1
    printf("enter value: ");
    for(int j=0; j<SIZE; j++){
        scanf("%d", array+j);
    }
    insertion_sort(array, SIZE);
    int i;
    for(i=0; i<SIZE-1; i++){
        printf("%d,", *(array+i));
    }
    printf("%d\n", *(array+i));
    return 0;
}