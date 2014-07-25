//pg 367 j
#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int i,n,d=1;;
      char a[25];
      gets(a);
      n=strlen(a);
      for(i=0;i<n;i++)
      {
                      if(a[i]=='a'&&a[i+1]=='a')d++;
      }
      printf("%d",d);
      getch();
}
