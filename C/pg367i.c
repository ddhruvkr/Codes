#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int i,j,e,d,n,x;
      char c;
      scanf("%d\n",&n);
      char a[n][25];
      for(i=0;i<n;i++)
      scanf("%s\n",&a[i][0]);
      for(i=0;i<n;i++)
      {
                      x=0;
                      c=a[i][0];
                      while(a[i][x]!='\0'){x++;}
                      for(j=0;j<=x;j++)
                      {
                               if(a[i][j]==' '){printf("%c.",c);d=j;c=a[i][j+1];}
                               else if(a[i][j]=='\0')
                               for(e=d+1;e<x;e++)
                               printf("%c",a[i][e]);
                      }
      }
      getch();
}
                                    
            
