#include <stdio.h>
#include <conio.h>
main()
{
      int x;
      printf("No of records you want to store\n");
      scanf("%d",&x);
      struct aa
      {
             char name[50];
             char roll[50];
       };
       struct dob
       {
              struct aa s[x];
              int date[3];
       };
              struct dob a[x];
       int i;
       for(i=0;i<x;i++)
       {
            printf("Enter the student's name\n");
            scanf("%s",&a[i].s[i].name);
            printf("enter your roll number\n");
            scanf("%s",&a[i].s[i].roll);
            printf("Enter date\n");
            scanf("%d",&a[i].date[0]);
            printf("Enter month\n");
            scanf("%d",&a[i].date[1]);
            printf("Enter year\n");
            scanf("%d",&a[i].date[2]);
       } 
       for(i=0;i<x;i++)
       {
            printf("S. No.%d->\t",i+1);           
            printf("%s\t",a[i].s[i].name);
            printf("%s\t",a[i].s[i].roll);
            printf("%d\t",a[i].date[0]);
            printf("%d\t",a[i].date[1]);    
            printf("%d\t",a[i].date[2]);
            printf("\n");
       }
       getch();
}
            
            
              
       
       
