#include<stdio.h>
#include <conio.h>
main()
{
int i,a,b,c;
printf("Enter a number(Only Integer): ");
scanf("%d",&a);
char s[][10]={"Violet","Indigo","Blue","Green","Yellow","Orange","Red"};
for(i=7;i>=0;i--)
{
b= 1<<i;
c= a&b;
//c==0?printf("0"):printf("1");
if(c!=0)printf("%s\n",&s[i][0]);
}
printf("\n");
getch();
}
