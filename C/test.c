#include <stdio.h>
#include <conio.h>
main()
{
      int i,a=0,n,m;
      char s[25];
      gets(s);
      scanf("%d %d",&n,&m);
      char r[m-n+1];
      for(i=n-1;i<m;i++)
      {r[a]=s[i];a++;}
      for(i=0;i<m-n+1;i++)
      printf("%c",r[i]);
      printf("\n");
     // puts(r);
      getch();
}
