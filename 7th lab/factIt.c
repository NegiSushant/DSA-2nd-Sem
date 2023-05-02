#include<stdio.h>
void main(){
    int num, fact =1;
    printf("Enter the number which fatorial you want: ");
    scanf("%d", &num);
    for(int i = num; i >= 2; i--){
        fact *= i;
        
    }
    printf("factorial of %d is: %d",num, fact);
}