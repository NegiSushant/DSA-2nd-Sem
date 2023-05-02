#include<stdio.h>
int fibbo(int num);
void main(){
    int num;
    printf("Enter the number which factorial you want: ");
    scanf("%d",&num);
    printf("%dth term of fibonacci series is: %d", num, fibbo(num));
}

int fibbo(int num){
    if(num <= 1){
        return num;
    }else{
        return fibbo(num - 1) + fibbo(num -2);
    }
}