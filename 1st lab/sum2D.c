#include<stdio.h>
void main(){
    int arr[10][10], arr2[10][10], sum[10][10], r1, r2, c1, c2;
    printf("Enter the row and coloumn of 1st Array: ");
    scanf("%d%d",&r1,&c1);

    printf("Enter the row and coloumn of 2nd Array: ");
    scanf("%d%d",&r2,&c2);

    while (r1!=r2 && c1!=c2){
        printf("Error! Column and Row of each array must be equql.\n");
        printf("Enter the row and coloumn of 1st Array: ");
        scanf("%d%d",&r1,&c1);

        printf("Enter the row and coloumn of 2nd Array: ");
        scanf("%d%d",&r2,&c2);
    }
    
    printf("Enter the elements in first array: ");
    for(int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n\n");
    printf("\n\n");
    printf("Enter the elements in second array: ");
    for(int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    printf("Sum of matrixes are: \n");
    for (int i = 0; i < r1; i++){
        for(int j =0; j < c1; j++){
            sum[i][j]= 0;
            sum[i][j] += arr[i][j] +arr2[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    
}