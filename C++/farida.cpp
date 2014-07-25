# include <cstdio>
# include <algorithm>
using namespace std;
int main()
{
	int t,n,i,c=0,j;
	long long int max,max1;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		c++;
		long long int a[n];
		for(i=0;i<n;i++)scanf("%lld",&a[i]);
		if(n==0)printf("Case %d: 0\n",c);
		else if(n==1)printf("Case %d: %lld\n",c,a[0]);
		else if(n==2) {
            if(a[0]>a[1])printf("Case %d: %lld\n",c,a[0]);
			else printf("Case %d: %lld\n",c,a[1]);
		}
		else {
			max=a[0];
			max1=a[1];
			for(i=2;i<n;i++) {
				a[i]+=max;
				if(max<max1)max=max1;
				max1=a[i];
			}
			if(max>max1)printf("Case %d: %lld\n",c,max);
			else
			 printf("Case %d: %lld\n",c,max1);
		}
	}
	return 0;
}
