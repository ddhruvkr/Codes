# include <stdio.h>
int main()
{
	int w;
	long long n,x,t;
	scanf("%d",&w);
	while(w--) {
		scanf("%lld",&n);
		x=1;
		if(n!=1)
		{
			n--;t=2;x=1;
			while(n!=0) {
			if(n>t){x=x*t;n-=t;t++;}
			else {x=x*(n-t);n-=t;}
			x=x%1000000007;
			}
			x=x%1000000007;
	    }
	    printf("%lld\n",x);
	}
	return 0;
}
