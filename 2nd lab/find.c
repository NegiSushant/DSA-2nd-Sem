#include<stdio.h>
void oneD(int base, int w, int k);
void twoDR(int base, int w, int n, int L1, int L2, int i, int j);
void twoDC(int base, int w, int m, int L1, int L2, int i, int j);

void main(){
    int base, w, k, L1, L2, i, j, m;

    int n;
    printf("For 1 D enter: 1\nFor 2D row wise enter: 2\nFor 2D coloumn wise enter 3:\n");
    scanf("%d", &n);
    switch (n){
    case 1:
        oneD(base, w, k);
        break;
    case 2:
        twoDR(base, w, n, L1, L2, i, j);
        break;
    
    case 3:
        twoDR(base, w, m, L1, L2, i, j);
        break;

    default:
        printf("Invailid Input!");
        break;
    }
}

void oneD(int base, int w, int k){
    int loc;

    printf("Enter the base addres: ");
    scanf("%d", &base);

    printf("Enter the number of word per memory cell: ");
    scanf("%d", &w);

    printf("Enter the element which address you want: ");
    scanf("%d", &k);

    loc = base + (w * k);

    printf("Base address of %dth element is: %d", k, loc);


}

void twoDR(int base, int w, int n, int L1, int L2, int i, int j){
    int loc;

    printf("Enter the base addres: ");
    scanf("%d", &base);

    printf("Enter the number of word per memory cell: ");
    scanf("%d", &w);

    printf("Enter the number of column: ");
    scanf("%d", &n);

    printf("Enter the lower bound of row: ");
    scanf("%d", &L1);

    printf("Enter the lower bound of col: ");
    scanf("%d", &L2);

    printf("Enter the row which addresh you want: ");
    scanf("%d", &i);

    printf("Enter the colomun which address you want: ");
    scanf("%d", &j);

    loc = base + w*(n*(i-L1) + (j-L2));

    printf("Base address is: %d", loc);
}

void twoDC(int base, int w, int m, int L1, int L2, int i, int j){
    int loc;

    printf("Enter the base addres: ");
    scanf("%d", &base);

    printf("Enter the number of word per memory cell: ");
    scanf("%d", &w);

    printf("Enter the number of row: ");
    scanf("%d", &m);

    printf("Enter the lower bound of row: ");
    scanf("%d", &L1);

    printf("Enter the lower bound of col: ");
    scanf("%d", &L2);

    printf("Enter the row which addresh you want: ");
    scanf("%d", &i);

    printf("Enter the colomun which address you want: ");
    scanf("%d", &j);

    loc = base + m*(w*(i-L1) + (j-L2));

    printf("Base address is: %d", loc);
}