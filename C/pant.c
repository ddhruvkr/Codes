#include <stdio.h>
#include <conio.h>
main()
{
struct aa
{
       char name[50];
       char roll[50];
};
       struct dob
       {
              struct aa s[4];
              int date[3];
       };
              struct dob a[4];
       int i;
       for(i=0;i<4;i++)
       {
            printf("Enter your name");
            scanf("%s",&a[i].s[i].name);
            printf("enter your roll number");
            scanf("%s",&a[i].s[i].roll);
            printf("Enter date");
            scanf("%d",&a[i].date[0]);
            printf("Enter month");
            scanf("%d",&a[i].date[1]);
            printf("Enter year");
            scanf("%d",&a[i].date[2]);
       }
       for(i=0;i<4;i++)
       {
            printf("%d record",i);           
            printf("%s\t",a[i].s[i].name);
            printf("%s\t",a[i].s[i].roll);
            printf("%d\t",a[i].date[0]);
            printf("%d\t",a[i].date[1]);    
            printf("%d\t",a[i].date[2]);
            printf("\n");
       }
       getch();
}
            
            
              
       
       
