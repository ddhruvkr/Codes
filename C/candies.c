#include <stdio.h>
#include <conio.h>
main()
{
      int z,i,T,N,x,d,t,w,min,u,j,l;
      scanf("%d",&T);
      for(i=1;i<=T;i++)
      {
                       d=0;
                       scanf("%d",&N);
                       int C[25];
                       for(j=0;j<N;j++)
                       scanf("%d",&C[j]);
                       min=C[0];
                       for(j=1;j<N;j++)
                       if(min>C[j]){min=C[j];d=j;}
                       t=d;
                       u=0;w=0;l=0;
                       if(min!=C[0])
                       {     
                               while(min!=C[0])
                               {
                                     if(t==0){t=N-1;}          
                                     if(min==C[t])
                                     {          
                                     C[t-1]--;
                                     C[t]++;
                                     min=C[t];
                                     for(z=1;z<N;z++)if(C[0]==C[z])u++;
                                     if(u==N-1)break;
                                     for(z=0;z<N-1;z++)if(C[z]<=C[z+1])w++;
                                     if(w==N-1){l=1;break;}
                                     for(x=0;x<t;x++)
                                     if(C[x]<min){min=C[x];t=x;}
                                     }
                               }
                       }
                       if(l==0)
                       printf("%d\n",min);
                       else
                       printf("%d\n",C[0]);
      }
      getch();
}
