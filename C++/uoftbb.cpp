#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long t,j;
	long long damage[1001];
	scanf("%lld",&t);
	while(t--){
    	long long l,m,n,i,max,min,y;
    	cin>>l>>n;
    	long long c[n+1],r[n+1],d[n+1];
    	for(i=1;i<=n;++i)
        	cin>>c[i]>>r[i]>>d[i];
    	cin>>m;
    	long long h[m];
    	for(i=0;i<m;++i)
        	cin>>h[i];
        for(i=1;i<=l;++i)
    	damage[i]=0;
    	for(i=1;i<=n;i++) {
			if(c[i]-r[i]<0)min=0;
			else min=c[i]-r[i];
			if(c[i]+r[i]>l)max=l;
			else max=c[i]+r[i];
			for(j=min;j<=max;j++)damage[j]+=d[i];
    	}
    	for(i=0;i<m;i++) {
			y=0;
			for(j=1;j<=l;j++) {
				if(h[i]-damage[j]>0)h[i]-=damage[j];
				else {y=j;j=l+1;h[i]=0;}
			}
			if(h[i]>0)printf("Bloon leakage\n");
			else printf("%lld\n",y);
    	}
	}
    return 0;
}
