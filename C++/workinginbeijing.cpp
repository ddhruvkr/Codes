# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int t,q,m;
	long long a,b,n,cost,i,j;
	scanf("%d",&t);
	q=0;
	while(t--) {
		q++;
		scanf("%lld%lld%lld",&n,&a,&b);
		int arr[n];
		cost=0;
		for(i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			cost=cost+b;
		}
		j=0;
		m=0;
		if(n==1)cost=cost+a;
		for(i=1;i<n;i++) {
			if(m==0)cost=cost+a;
			if((arr[i]-arr[j]-1)*b <= 2*a){cost=cost+(arr[i]-arr[j]-1)*b;m=1;}
			else {cost=cost+a;m=0;}
			j++;
		}
		cost=cost+a;
		printf("Case #%d: %lld",q,cost);
		printf("\n");
	}
	getch();
	return 0;
}
