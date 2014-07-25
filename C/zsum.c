# include <stdio.h>
long long int power(long long x,long long y,long long result)
{
    long long int r=10000007;
    //long long int result= 1;
    while(y>0)
    {
        if(y%2==1){
            result=(result*x)%r;
        }
        y=y>>1;
        x=(x*x)%r;
    }
    return result%r;
}
void print()
{

	for(i=l.begin();i!=l.end();i++)
	printf("%d  " , *i);
	printf("\n");
}
int main()
{
	long long n,k,s,d,e,f;
	scanf("%lld%lld" , &n,&k);
	while(n!=0 && k!=0) {
		if(n>k) {
		s=power(n,k,1);
		s=s+power(n,n-k,s);
		s=s%10000007;
		d=power(n-1,k,1);
		d=d+power(n-1,n-1-k,d);
		d=d%10000007;
		d=2*d;
		d=d%10000007;
		s=s+d;
		s=s%10000007;
	    }
	    else if(n<k) {
		s=power(n,n,1);
		s=s+power(n,k-n,s);
		s=s%10000007;
		d=power(n-1,n-1,1);
		d=d+power(n-1,k-n+1,d);
		d=d%10000007;
		d=2*d;
		d=d%10000007;
		s=s+d;
		s=s%10000007;
	    }
	    else if(n==k) {
			s=power(n,n,1);
			d=power(n-1,n-1,1);
			d=d*n;
			d=d%10000007;
			s=s+d;
			s=s%10000007;
			s=2*s;
			s=s%10000007;
	    }
	    printf("%d\n" , s);
		scanf("%lld%lld" , &n,&k);
	}
	return 0;
}
