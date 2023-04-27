#include <stdio.h>
#include <stdlib.h>

// defining structure of a node
typedef struct nodeType
{
    int info;
    struct nodeType *next;
} node;

// function prototypes
void createEmptyList(node **head);
void traverseInOrder1(node *head);
void traverseInReverseOrder(node *head);
node *searchInUnsortedList(node *head, int item);
void auxilarySearch(node *head, node **ploc, node **loc, int item);
void insertAtBegining(node **head, int item);
void insertAfterElement(node *head, int item, int after);
void insertAtEnd(node **head, int item);
void deleteFromBeginning(node **head);
void deleteFromEnd(node **head);
void deleteAfterElement(node *head, int after);
void reverseList(node **head);
void deleteList(node **head);

void main()
{
    node *head;
    int choice, element, after;
    createEmptyList(&head);
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
            printf("\nEnter element : ");
            scanf("%d", &element);
            insertAtBegining(&head, element);
            break;

        case 2:
            printf("\nEnter element :");
            scanf("%d", &element);
            insertAtEnd(&head, element);

        case 3:
            printf("\nEnter element :");
            scanf("%d", &element);
            printf("\nEnter element after which to insert :");
            scanf("%d", &after);
            insertAfterElement(head, element, after);
            break;

        case 4:
            if (head == NULL)
                printf("\nList is Empty.....");
            traverseInOrder1(head);
            printf("\n\nPress any key to continue......");
            break;

        case 5:
            if (head == NULL)
                printf("\nList is empty.....");
            else
                traverseInReverseOrder(head);
            printf("\n\n Press any key to continue......");
            break;

        case 6:
            deleteFromBeginning(&head);
            break;

        case 7:
            deleteFromEnd(&head);
            break;

        case 8:
            printf("\nEnter element after which to delete :");
            scanf("%d", &after);
            deleteAfterElement(head, after);
            break;

        case 9:
            reverseList(&head);
            break;

        case 10:
            deleteList(&head);
            exit(1);
        }
    }
} // End of main function

void createEmptyList(node **head)
{
    *head = NULL;
}
void traverseInOrder1(node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->info);
        head = head->next;
    }
}

void traverseInReverseOrder(node *head)
{
    if (head != NULL)
        traverseInReverseOrder(head->next);
    printf("%d ->", head->info);
}

node *searchInUnsortedList(node *head, int item)
{
    while ((head != NULL) && (head->info != item))
    {
        head = head->next;
        return head;
    }
}
node *searchInSortedList(node *head, int item)
{
    while (head != NULL)
    {
        if (head->info == item)
        {
            return head;
        }
        else if (item < head->info)
        {
            return NULL;
        }
        else
        {
            head = head->next;
        }
    }
    return NULL;
}

void auxilarySearch(node *head, node **ploc, node **loc, int item)
{
    int flag = 0;
    if (head == NULL) // if list id empty
        *ploc = *loc = NULL;
    else if (head->info == item) // if item present in first node
    {
        *ploc = NULL;
        *loc = NULL;
    }
    else
    {
        *ploc = head;
        *loc = head->next;
        while ((*loc != NULL) && (!flag))
        {
            if ((*loc)->info == item)
                flag = 1;
            else
            {
                *ploc = *loc;
                *loc = (*loc)->next;
            }
        }
    }
}

void insertAtBegining(node **head, int item)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    if (*head == NULL) // list initialy empty
        ptr->next = NULL;
    else
        ptr->next = *head;
    *head = ptr;
}

void insertAtEnd(node **head, int item)
{
    node *ptr, *loc;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = NULL;
    if (*head == NULL) // list initialy empty
        *head = ptr;
    else
    {
        loc = *head;
        while (loc->next != NULL)
        {
            loc = loc->next;
            loc->next = ptr;
        }
    }
}

void insertAfterElement(node *head, int item, int after)
{
    node *ptr, *loc;
    loc = searchInUnsortedList(head, after);
    if (loc == (node *)NULL) // element after not found
        return;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = loc->next;
    loc->next = ptr;
}

void deleteFromBeginning(node **head)
{
    node *ptr;
    if (*head == NULL)
        return;
    else
    {
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

void deleteFromEnd(node **head)
{
    node *ptr, *loc;
    if (*head == NULL)
        return;
    else if ((*head)->next == (node *)NULL)
    {
        ptr = *head;
        *head = NULL;
        free(ptr);
    }
    else
    {
        loc = *head;
        ptr = (*head)->next;
        while (ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }
        loc->next = NULL;
        free(ptr);
    }
}

void deleteAfterElement(node *head, int after)
{
    node *ptr, *loc;
    loc = searchInUnsortedList(head, after);
    if (loc == (node *)NULL) // element after not found
        return;
    ptr = loc->next;
    loc->next = ptr->next;
    free(ptr);
}

void reverseList(node **head)
{
    node *previousNode, *currentNode, *nextNode;
    currentNode = *head;
    nextNode = currentNode->next;
    previousNode = NULL;
    currentNode->next = NULL;
    while (nextNode != NULL)
    {
        previousNode = currentNode;
        currentNode = nextNode;
        nextNode = currentNode->next;
        currentNode->next = previousNode;
    }
    *head = currentNode;
}

void deleteList(node **head)
{
    node *ptr;
    while (*head != NULL)
    {
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}