#include<stdio.h>
#include<stdlib.h>

typedef struct nodetype{
    int info;
    struct nodetype *prev;
    struct nodetype *next;
}node;

//Create Empty Linked List
void CreateEmptyList(node **head, node **tail){
    *head = *tail = NULL;
}

//Traverse in Order
void TraverseInOrder(node *head){
    while (head!= NULL)
    {
        printf("%d->", head->info);
        head = head->next;
    }
    
}

//Travesre in Reverse order
void TraverseInRev(node *tail){
    while (tail!=NULL){
        printf("%d<-", tail->info);
        tail = tail->prev;

    }
    
}

//Insert At Begnning
void InsertAtBeginnig(node **head, node **tail, int item){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr ->info = item;
    if(*head == NULL){
        ptr->next = ptr->prev = NULL;
        *head = *tail = ptr;

    }else{
        ptr->prev = NULL;
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
}

//Insert At End

void InsertAtEnd(node **head, node **tail, int item){
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr -> info = item;

    if(*head == NULL){
        *head = *tail = ptr;

    }else{
        ptr->next = NULL;
        ptr->prev = *tail;
        (*tail)->next = ptr;
        *tail = ptr;
    }
}
void main(){
    node *head, *tail;
    int choice, element, after;
    CreateEmptyList(head, tail);
    while (1)
    {
        printf("        Options available\n        ");
        printf("++++++++++++++++++++++++++++++++++++\n\n");
        printf("1. Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert after a given element\n");
        printf("4.Traverse in order\n");
        printf("5.Traverse in Reverse in order\n");
        printf("6.Delete from beginning\n");
        printf("7.Delete from End\n");
        printf("8.Delete after a givrn element\n");
        printf("9.Reverse Linked list\n");
        printf("10.Exit\n\n");

        printf("Enter your choice(1-10):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            break;
        
        default:
            break;
        }
    }
    
}