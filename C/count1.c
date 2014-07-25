#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
  {
   char str[100];
   int i=0,m=0,n=0;
   printf("enter the string");
   gets(str);
   while(str[i]!='\0')
   {
   if((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u'));
   m++;
   if((str[i]>='0')&&(str[i]<='9'));
   n++;
   i++;
   }
   printf("no of vovles:%d",m);
   printf("no of digits:%d",n);
   getch();
   return 0;
     }           
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    
