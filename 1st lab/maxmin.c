#include<stdio.h>

void main(){
    int max, min;
    int arr[5];

    printf("Enter the elements in array: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    
    max = arr[0];
    for(int i = 1; i<5; i++){
        if(max < arr[i]){
            max=arr[i];
        }
    }

    printf("Max element is: %d\n", max);

    min= arr[0];
    for(int i = 1; i<5; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }

    printf("Min element is: %d", min);
}