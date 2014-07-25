#include <stdio.h>
#include <conio.h>
int main()
{
    int i,t,m,n,s=0,p;
    scanf("%d",&t);
    while(t--)
    {
     scanf("%d %d",&m,&n);
     int a[n+1];
     for(i=0;i<=n;i++)
      a[i]=i;
      for(i=2;i<=n;i++)
      {
                       p=i;s=0;
                       while((i+s)<=n)
                       {
                                      if(a[i]==0)
                                       break;
                                      a[i+p]=0;
                                      p=i+p;
                                      s=p;
                                      }
                                      }
                                      for(i=m;i<=n;i++)
                                       {
                                        if(a[i]!=0)
                                        printf("%d\n",a[i]);
                                      }
}                                      getch();
                                      return 0;
                                      }
