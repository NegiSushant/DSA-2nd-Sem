/*Implementation of Circular list*/
#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *next;
} node;
node *head = NULL;
void insert_cir_end(node *h, int d)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
        return;
    }
    while (h->next != head)
        h = h->next;
    temp->next = h->next;
    h->next = temp;
}
//-----------------------------------------------------------------
void insert_cir_beg(node *h, int d)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
        return;
    }
    while (h->next != head)
        h = h->next;
    temp->next = head;
    head = temp;
    h->next = head;
}
//--------------------------------------------------------------
node *find(node *h, int aft)
{
    while (h->next != head && h->data != aft)
        h = h->next;
    if (h->next == head && h->data != aft)
        return (node *)NULL;
    else
        return h;
}
//--------------------------------------------------------------
void insert_cir_after(node *h, int aft, int d)
{
    node *temp, *loc;
    loc = find(h, aft);
    if (loc != (node *)NULL)
    {
        temp = (node *)malloc(sizeof(node));
        temp->data = d;
        temp->next = loc->next;
        loc->next = temp;
    }
    else
        printf("\nElement Not found.");
}
//---------------------------------------------------------------------
void insert_cir_sp_pos(node *h, int pos, int d)
{
    node *temp, *loc;
    int p = 0;
    while (h->next != head && p < pos - 1)
    {
        loc = h;
        p++;
        h = h->next;
    }
    if ((pos > p + 1 && h->next == head) || pos < 0)
    {
        printf("\nPosition not exists.");
        getch();
        return;
    }
    if ((p + 2) == pos)
    {
        loc = h;
    }
    temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = loc->next;
    if (pos == 1)
    {
        h = head;
        while (h->next != head)
            h = h->next;
        h->next = temp;
        head = temp;
    }
    else
        loc->next = temp;
}
//--------------------------------------------------------------------
void display(node *h)
{
    while (h->next != head)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("%d ", h->data);
}
//--------------------------------------------------------------------
void delete_cir_beg(node *h)
{
    node *temp;
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    if (h->next == head)
    {
        printf("\nNode deleted.List is empty");
        head = NULL;
        free(h);
        return;
    }
    temp = head;
    while (h->next != head)
        h = h->next;
    head = head->next;
    h->next = head;
    free(temp);
}
//--------------------------------------------------------------------
void delete_cir_end(node *h)
{
    node *temp;
    if (head == NULL)
    {
        printf("\nList is empty");
        getch();
        return;
    }
    if (h->next == head)
    {
        printf("\nNode deleted.List is empty");
        getch();
        head = NULL;
        free(h);
        return;
    }
    while (h->next != head)
    {
        temp = h;
        h = h->next;
    }
    temp->next = h->next;
    free(h);
}
//--------------------------------------------------------------------
void delete_cir_after(node *h, int aft)
{
    node *temp;
    if (head == NULL)
    {
        printf("\nList is empty");
        getch();
        return;
    }
    if (h->next == head && h->data == aft)
    {
        printf("\nNode deleted.List is empty");
        getch();
        head = NULL;
        free(h);
        return;
    }
    temp = find(head, aft);
    if (temp != (node *)NULL)
    {
        if (temp->next == temp)
        {
            printf("\nSingle Node.Deletion not possible");
            getch();
            return;
        }
        if (temp->next == head)
        {
            head = head->next;
            temp->next = head;
            free(h);
        }
        else
        {
            h = temp->next;
            temp->next = h->next;
            free(h);
        }
    } // end of if(!temp)
}
//-------------------------------------------------------------------
void free_list(node *list)
{
    node *t;
    while (list != NULL)
    {
        t = list;
        list = list->next;
        free(t);
    }
}
//--------------------------------------------------------------------
void main()
{
    int opt = 0, val, pos, aft;
    while (1)
    {
        printf("\nCircular List Operations.");
        printf("\n\n****************************************");
        printf("\n1.Insert at begining.");
        printf("\n2.Insert at end.");
        printf("\n3.Insert after specific element.");
        printf("\n4.Insert at specific position.");
        printf("\n5.Delete from begining.");
        printf("\n6.Delete from end.");
        printf("\n7.Delete after specific element.");
        printf("\n8.View the List.");
        printf("\n9.Exit.");
        printf("\n\nEnter the option.");
        fflush(stdin);
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter the data");
            fflush(stdin);
            scanf("%d", &val);
            insert_cir_beg(head, val);
            break;
        case 2:
            printf("\nEnter the data");
            fflush(stdin);
            scanf("%d", &val);
            insert_cir_end(head, val);
            break;
        case 3:
            printf("\nEnter the data to be inserted.");
            fflush(stdin);
            scanf("%d", &val);
            printf("\nEnter the data after which to be inserted.");
            fflush(stdin);
            scanf("%d", &aft);
            insert_cir_after(head, aft, val);
            break;
        case 4:
            printf("\nEnter the data");
            fflush(stdin);
            scanf("%d", &val);
            printf("\nEnter the position at for insertion.");
            fflush(stdin);
            scanf("%d", &pos);
            insert_cir_sp_pos(head, pos, val);
            break;
        case 5:
            delete_cir_beg(head);
            break;
        case 6:
            delete_cir_end(head);
            break;
        case 7:
            printf("\nEnter the element after which is to be deleted.");
            fflush(stdin);
            scanf("%d", &aft);
            delete_cir_after(head, aft);
            break;
        case 8:
            printf("\nElements in the list");
            display(head);
            getch();
            break;
        case 9:
            free_list(head);
            exit(0);
        } // end of switch
    }     // end of while
} // end of main()