# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int t,n,m,D,i,j,br;
	int a[500];
	scanf("%d" , &t);
	while(t--) {
        scanf("%d" , &n);
        scanf("%d" , &m);
        scanf("%d" , &D);
        for(i=0;i<n;i++)scanf("%d" , &a[i]);
        j=0;
        i=m*D;
        br=0;
        while(i>0) {
			if(a[j]>D){a[j]=a[j]-D;i-=D;}
			else if(j<n-1)j++;
			else {br=1;break;}
		}
        if(br==1)printf("NO\n");
        else printf("YES\n");
	}
	getch();
	return 0;
}
