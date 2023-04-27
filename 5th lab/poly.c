#include<stdio.h>
typedef struct poly{
    int cof;
    int pow;
    struct poly *next;
}node;

void addpoly(node *ptr1, node *ptr2, node **ptr3){
    int powe;
    int coef;
    while((ptr1 != NULL) && (ptr2 != NULL)){
        if(ptr1->pow > ptr2->pow){
            coef = ptr1->cof;
            powe = ptr1->pow;
            ptr1 = ptr1->next;
        }else if(ptr1->pow < ptr2->pow){
            coef = ptr2 -> cof;
            powe = ptr2 -> pow;
            ptr2 = ptr2->next;
        }else{
            coef = ptr1 -> cof + ptr2->cof;
            powe = ptr1->pow;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 ->next;
        }
        if(coef != 0){
            addnode(ptr3, coef, powe);
        }
    }
    if (ptr1 == NULL)
    {
        for( ; ptr2 != NULL; ptr2 = ptr2->next){
            addnode(ptr3, ptr2->cof, ptr2->pow);
        }
    }else if(ptr2 == NULL){
        for( ; ptr1 != NULL; ptr1 =ptr1->next){
            addnode(ptr3, ptr1->cof, ptr1->pow);
        }
    }
    
}