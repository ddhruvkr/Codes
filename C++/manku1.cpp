/*# include <cstdio>
# include <conio.h>
# include <cmath>
int main()
{
	long long n,k=1,t=1,i,j,i1,w,l,count;
	char c[5][1000];
	int s[1000];
	for(i=0;i<1000;i++)s[i]=-1;
	for(i=0;i<1000;i++)c[0][i] = 'm';
	for(i=0;i<1000;i++)c[1][i] = 'a';
	for(i=0;i<1000;i++)c[2][i] = 'n';
	for(i=0;i<1000;i++)c[3][i] = 'k';
    for(i=0;i<1000;i++)c[4][i] = 'u';
   // scanf("%d" , &w);
   w=2;
    while(w--) {
		int br=0;
		scanf("%ld" , &n);
		s[0]=0;t=1;k=1;
		while(t!=100) {
			for(i=0;i<pow(5,t-1);i++) {
		//s[i]=0;
				for(j=0;j<5;j++) {
					s[t-1]=j;
					if(k==n) {
						l=0;
						while(s[l]!=-1){printf("%c" , c[s[l]][l]);l++;}
						printf("\n");
						//j=5,i=t,br=1;
      getch();
      return 0;
					}
					k++;
				}
                l=t-1;
				while(l>0 && i<t) {
					//printf("dhruv");
					if(s[l]==4 && s[l-1]<4){s[l-1]++;s[l]=0;}
					else if(s[l]==4 && s[l-1]==4)s[l]=0;
					l--;
				}
				//printf("%d%d" , s[0],s[1]);
				//l=0;
				//for(l=0;l<=i;l++)s[l]=0;
			}
			l=0;count=0;
		//printf("dhruv");
		    while(s[l]!=-1){count++;l++;}
		//printf("yeah");
			if(count==t){t++;l=0;while(l<t){s[l]=0;l++;}}
			
		//printf("%d%d" , s[0],s[1]);
		//getch();
		}
	}
}*/

#include<stdio.h>

int main()
{
    long long i,j,k,l,n,m,t;
    char a[]={' ','m','a','n','k','u'};
    char b[1000000];
    char c[1000000];
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
                     j=0;
                     scanf("%lld",&n);
                     while(n!=0)
                     {
                                k=n%5;
                                if(k==0)
                                {
                                        b[j++]='u';
                                        n=n-1;
                                }
                                else
                                {
                                    b[j++]=a[k];
                                }
                                n=n/5;
                     }
                     b[j]='\0';
                     l=0;
                     for(k=j-1;k>=0;k--)
                     {
                                        c[l++]=b[k];
                     }
                     c[l]='\0';
                     printf("%s\n",c);
    }

    return 0;
}
