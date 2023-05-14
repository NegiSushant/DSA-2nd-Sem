#include<stdio.h>
#include<stdlib.h>

typedef struct nodetype{
    int info;
    struct nodetype *prev;
    struct nodetype *next;
}node;
/*-------------Function prototyping----------------*/
void CreateEmptyList(node **head, node **tail);
void TraverseInOrder(node *head);
void TraverseInRev(node *tail);
node *search(node *head, int item);
void InsertAtBeginnig(node **head, node **tail, int item);
void InsertAtEnd(node **head, node **tail, int item);
void InsertAfterElement(node *head, node **tail, int item, int after);
void InsertBeforeElement(node **head, int item, int before);
void deleteFromBeginning(node **head, node **tail);
void deleteFromEnd(node **head, node **tail);
void deleteBeforeElement(node **head, int before);
void deleteAfterElement(node *head, node **tail, int after);
void deleteList(node **head, node **tail);



void main(){
    node *head, *tail;
    int choice, element, after, before;
    CreateEmptyList(&head, &tail);

    while (1)
    {
        printf("        Options available\n        ");
        printf("++++++++++++++++++++++++++++++++++++\n\n");
        printf("1. Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert after a given element\n");
        printf("4.Insert brfoe a given element\n");
        printf("5.Traverse in order\n");
        printf("6.Traverse in Reverse in order\n");
        printf("7.Delete from beginning\n");
        printf("8.Delete from End\n");
        printf("9.Delete after a given element\n");
        printf("10.Delete before a given element:\n");
        printf("11.Exit\n\n");

        printf("Enter your choice(1-10):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nenter the Element: ");
            scanf("%d", &element);
            InsertAtBeginnig(&head, &tail, element);
            break;
        
        case 2:
            printf("\nEnter the Element: ");
            scanf("%d", &element);
            InsertAtEnd(&head, &tail, element);
            break;

        case 3:
            printf("\nenter the Element: ");
            scanf("%d", &element);
            printf("\nEnter element after which to insert: ");
            scanf("$d", &after);
            InsertAfterElement(head, &tail, element, after);
            break;

        
        case 4:
            printf("\nenter the Element: ");
            scanf("%d", &element);
            printf("\nEnter element before which to insert: ");
            scanf("$d", &before);
            InsertBeforeElement(&head, element, before);
            break;

        case 5:
            if(head == NULL){
                printf("\nList is Empty: ");

            }else{
                TraverseInOrder(head);
            }
            printf("\n\nPress any key to continue:  ");
            getch();
            break;

        case 6:
            if(head == NULL){
                printf("\nList is Empty: ");

            }else{
                TraverseInRev(tail);
            }
            printf("\n\nPress any key to continue:  ");
            getch();
            break;
        
        case 7:
            deleteFromBeginning(&head, &tail);
            break;

        case 8:
            deleteFromEnd(&head, &tail);
            break;
        case 9:
            printf("\nEnter element after which to delete: ");
            scanf("%d", &after);
            deleteAfterElement(head, &tail, after);
            break;

        case 10:
            printf("\nEnter element before which to delete: ");
            scanf("%d", &before);
            deleteBeforeElement(&head, before);
            break;

        case 11:
            deleteList(&head, &tail);
            exit(1);

        default:
            printf("Insert vailid entery!");
            break;
        }
    }
    
}
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

//Search 
node *search(node *head, int item){
    while (head != NULL){
        if(head->info == item){
            return head;
        }
        head = head ->next;

    }
    return NULL;
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


//Insert AfterElement

void InsertAfterElement(node *head, node **tail, int item, int after){
    node *ptr, *loc;
    ptr = head;
    loc = search(ptr, after);
    if(loc == NULL){
        return;
    }
    ptr = (node *)malloc(sizeof(node));
    ptr ->info = item;
    if(loc->next == NULL){
        ptr->next = NULL;
        loc->next = ptr;
        ptr ->prev = *tail;
        *tail = ptr;

    }else{
        ptr->prev = loc;
        ptr->next = loc->next;
        (loc->next) ->prev = ptr;
        loc->next = ptr;
    }
}

//InsertBeforeElement
void InsertBeforeElement(node **head, int item, int before){
    node *ptr, *loc;
    ptr = *head;
    loc = search(ptr, before);
    if(loc == NULL){
        return;
    }
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    if(loc->prev= NULL){
        ptr->prev = NULL;
        loc->prev = ptr;
        ptr->next =*head;
        *head = ptr;
    }else{
        ptr->prev = loc->prev;
        ptr->next = loc;
        (loc->prev)->next = ptr;
        loc->prev = ptr;
    }
}

//Delete from Beginning
void deleteFromBeginning(node **head, node **tail){
    node *ptr;
    if(*head == NULL){
        return;
    }
    ptr = *head;
    if(*head == *tail){
        *head = *tail = NULL;
    }else{
        (ptr->next)->prev = NULL;
        *head = ptr->next;
    }
    free(ptr);
}

// Delete From End
void deleteFromEnd(node **head, node **tail){
    node *ptr;
    if(*head = NULL){
        return;

    }
    ptr = *tail;
    if(*head == *tail){
        *head = *tail = NULL;
    }else{
        (ptr->prev)->next = NULL;
        *tail = ptr->prev;
    }
    free(ptr);
}

//Delete After Elements
void deleteAfterElement(node *head, node **tail, int after){
    node *ptr, *loc;
    ptr = head;
    loc = search(ptr, after);
    if(loc == NULL){
        return;
    }else if((loc->next)->next == NULL){
        ptr = loc->next;
        loc->next = NULL;
        *tail = loc;
        free(ptr);
    }else{
        ptr = loc->next;
        loc->next = ptr->next;
        (ptr->next)->prev = loc;
        free(ptr);
    }
}

//Delete before elements
void deleteBeforeElement(node **head, int before){
    node *ptr, *loc;
    ptr = *head;
    loc = search(ptr, before);
    if(loc == NULL){
        return;
    }else if((loc->prev)->prev == NULL){
        ptr = loc->prev;
        loc->prev= NULL;
        *head = loc;
        free(ptr);
    }else{
        ptr = loc->prev;
        loc->prev = ptr->prev;
        (ptr->prev)->next = loc;
        free(ptr);
    }
}

//Delete list
void deleteList(node **head, node **tail){
    node *ptr;
    while(*head != NULL){
        ptr = *head;
        *head = (*head) -> next;
        free(ptr);
    }
    *tail = NULL;
}