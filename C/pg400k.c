#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;
 
void add(int);
void Display();
NODE *start;
int z=0;
   /* Global Declarations */
 
main()
{
    /* Main Program */
    int opn,elem;
    start = (NODE *)malloc(sizeof(NODE));
    start->link=NULL; 
    do
    {
        printf("\n ### Linked List Implementation ### \n\n");
        printf("\n Press 1-add,2-Display,3-Exit\n");
        printf("\n Your option ? ");
        scanf("%d",&opn);
        switch(opn)
        {
        case 1:
            printf("\n\nRead the Element to be added ?");
            scanf("%d",&elem);
            add(elem);
            break;
        case 2: printf("Linked List Implementation: Status:\n");
            Display(); break;
        case 3: printf("\n\n Terminating \n\n"); break;
        default: printf("\n\nInvalid Option !!! Try Again !! \n\n");
            break;
        }
    }while(opn != 3);
    getch();
}
 
void add(int info)
{
     int q=0,e=0;
    NODE *temp,*t,*p;
    z++;
    temp=(NODE *)malloc(sizeof(NODE));
    if( temp == NULL)
        printf(" Out of Memory !! Overflow !!!");
    else
    {
        temp->data=info;
        temp->link=NULL;
        t=start;
        if(z==1){start->link=temp;}
        e=0;
        while(q==0&&z!=1)
        {
                   e++;      
                   if((t->link)->data<info && t->link!=NULL){t=t->link;}
                   if(t->link==NULL){q=2;}
                  else if((t->link)->data>info)q=1;
                  
        }
        if(q==2)t->link=temp;
        if(q==1)
        {p=t->link;
        t->link=temp;
        t=temp;
        temp->link=p;}
        printf(" Node has been inserted Successfully !!");
    }
}
  
void Display()
{
    NODE *t;
    if( start == NULL) printf("Empty\n");
    else
    {
        t=start->link;
        printf("start->");
        while(t)
        {
            printf("[%d]->",t->data);
            t=t->link;
        }
        printf("Null\n");
    }
}
