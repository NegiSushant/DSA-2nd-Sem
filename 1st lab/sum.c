#include<stdio.h>
void main(){
    int sum = 0;
    int arr[5];
    printf("Eneter the elements in Array: ");
    for (int i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < 5; i++){
        sum+=arr[i];
    }
    printf("Sum of elements of Array: %d",sum);
}