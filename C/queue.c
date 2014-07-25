#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;

void add(int);
int  delete();
void Display();
NODE *front=NULL;
NODE *rear=NULL;   /* Global Declarations */

main()
{
    /* Main Program */
    int opn,elem;
    do
    {
        printf("\n ### Linked List Implementation of QUEUE Operations ### \n\n");
        printf("\n Press 1-add, 2-delete, 3-Display,4-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1:
            printf("\n\nRead the Element to be added ?");
            scanf("%d",&elem);
            add(elem);
            break;
        case 2:
            elem=delete();
            if(elem != -1)
                printf(" Deleted Node(From Front)with the Data: %d\n",elem);
            break;
        case 3: printf("Linked List Implementation of Queue: Status:\n");
            Display(); break;
        case 4: printf("\n\n Terminating \n\n"); break;
        default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    }while(opn != 4);
    getch();
}

void add(int info)
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    if( temp == NULL)
        printf(" Out of Memory !! Overflow !!!");
    else
    {
        temp->data=info;
        temp->link=NULL;
        if(front == NULL) { front = rear = temp; }/* First Node? */
        else
        { rear -> link = temp;
        rear = temp; }       /* Insert End */
        //if(front==rear)
        //front->link=rear;
        //rear->data=info;
        printf(" Node has been inserted at Rear Successfully !!");
    }
}

int delete()
{
    int info;
    NODE *t;
    if( front ==  NULL) { printf(" Underflow!!!"); return -1; }
    else
    {
        t=front;
        info=front->data;
        if(front == rear) rear=NULL;
        front=front->link;
        t->link=NULL;
        free(t);
        return(info);
    }
}

void Display()
{
    NODE *t;
    if( front == NULL) printf("Empty Queue\n");
    else
    {
        t=front;
        printf("Front->");
        while(t)
        {
            printf("[%d]->",t->data);
            t=t->link;
        }
        printf("Null\n");
    }
}
