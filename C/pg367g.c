#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int x=-1,i=0,l=0,l1,d=0,d1=0;
      char a[25];
      char r[25];
      gets(a);
      l=strlen(a);
      for(i=0;i<l;i++)
      if(a[i]!=' '){r[++x]=a[i];d1++;}
      else d++;
      l1=strlen(r);
      printf("%d %d %d",l1,l,d1);
      for(i=0;i<l-d;i++)
      printf("%c",r[i]);
      getch();
}
                      
