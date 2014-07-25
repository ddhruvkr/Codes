#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;
 
void Push(int);
int  pop();
void Display();
NODE *top=NULL;   /* Global Declarations */
 
main()
{
    /* Main Program */
    int opn,elem;
    do
    {
        printf("\n ### Linked List Implementation of STACK Operations ### \n\n");
        printf("\n Press 1-Push, 2-Pop, 3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1:
            printf("\n\nRead the Element tobe pushed ?");
            scanf("%d",&elem);
            Push(elem);
            break;
        case 2:
            elem=Pop();
            if(elem != -1)
                printf(" Deleted Node(From Top)with the Data: %d\n",elem);
            break;
        case 3: printf("Linked List Implementation of Stack: Status:\n");
            Display(); break;
        case 4: printf("\n\n Terminating \n\n"); break;
        default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
        printf("\n\n\n\n  Press a Key to Continue . . . ");
        getch();
    }while(opn != 4);
}
 
void Push(int info)
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if( temp == NULL)
        printf(" Out of Memory !! Overflow !!!");
    else
    {
        temp->data=info;
        temp->link=top;
        top=temp;
        printf(" Node has been inserted at Top(Front) Successfully !!");
    }
}
 
int Pop()
{
    int info;
    NODE *t;
    if( top ==  NULL) { printf(" Underflow!!!"); return -1; }
    else
    {
        t=top;
        info=top->data;
        top=top->link;
        t->link=NULL;
        free(t);
        return(info);
    }
}
 
void Display()
{
    NODE *t;
    if( top == NULL) printf("Empty Stack\n");
    else
    {
        t=top;
        printf("Top->");
        while(t)
        {
            printf("[%d]->",t->data);
            t=t->link;
        }
        printf("Null\n");
    }
}
