#include <stdio.h>
#include <conio.h>
main()
{
      struct lnk
      {
             char s[5]={ ,1,2,4,5};
             char *a[5];
      }b;
      for(i=0;i<4;i++)
      b.a[i]=&b.s[i+1];
      int *n,*t;
      int e=1;
      t=b.a[3];
      b.a[3]=n;
      n=t;
      i=0;
      while(i<4)
      {
                      printf("%d\n",*b.a[i]);
                      i++;
      }
      getch();
}
                      
      
