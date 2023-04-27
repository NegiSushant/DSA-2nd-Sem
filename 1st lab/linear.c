#include<stdio.h>

void main(){
    int num, found =0;
    int arr[5];

    printf("Enter the elements in array: ");
    for (int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element which you want: ");
    scanf("%d", &num);

    for (int i = 0; i < 5; i++){
        if(num == arr[i]){
            found = 1;
        }
    }

    if(found == 1){
        printf("Element found!");
    }else{
        printf("Element not found!");
    }
    
    
}