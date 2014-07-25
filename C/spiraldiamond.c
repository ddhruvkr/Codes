#include <stdio.h>
#include <conio.h>
main()
{
      int i=0,x=1,n,j,q,z=0,y=0,v=0;
      scanf("%d",&n);
      int a[n][n];
      for(i=0;i<n;i++)
      {
                      for(j=0;j<n;j++)
                      a[i][j]=0;
      }
      for(q=1;q<=(n-1)/2;q++)
      {
      	for(i=((n-1)/2)-z,j=y;i>=v;i--,j++)
      	a[i][j]=x++;
      i=i+2;
      for(;i<=(n-1)/2;i++,j++)
      a[i][j]=x++;
      j=j-2;
      for(;j>=(n-1)/2;i++,j--)
      a[i][j]=x++;
      i=i-2;
      for(;i>=(n+1)/2;i--,j--)
      a[i][j]=x++;
      j++;
      a[i][j]=x++;
      j++;
      v++;
      if(q==1){y=y+2,z++;}
      else y++;
      }
      for(i=0;i<n;i++)
      {
                      for(j=0;j<n;j++)
                      if(a[i][j]==0)printf(" \t");
                      else printf("%d\t",a[i][j]);
                      printf("\n\n\n");
      }
      getch();
}
      
      
