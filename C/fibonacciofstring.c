#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      char a[50]="a";
      char b[50]="b";
      printf("%s\n",a);
      printf("%s\n",b);
      int i;
      char temp[50];
      for(i=2;i<6;i++)
      {
                    strcpy(temp,b);
                    strcat(b,a); 
                    strcpy(a,temp);
                    printf("%s\n",b);
      }
      getch();
} 
