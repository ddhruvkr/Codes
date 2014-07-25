#include <stdio.h>
#include <conio.h>
main()
{
      //struct lnk
      //{
      //   char s[]={ ,1,2,4,5};
      //     char *a[5];
      //}b;
      int s[]={0,1,2,4,5};
      char *a[5];
      int g=3;
      int *n,*t;
      n=&g;
      int i;
      for(i=0;i<4;i++)
      a[i]=&s[i+1];
      
      int e=1;
      t=a[2];
      a[2]=n;
      n=t;
      
      i=0;
      while(i<4)
      {
                      printf("%d\n",*a[i]);
                      i++;
                      if(i==3)printf("%d\n",*n);
      }
      getch();
}
                      
      
