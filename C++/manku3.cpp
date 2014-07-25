#include<stdio.h>
long long mul_inv(long long a, long long b)
{
	long long b0 = b, t, q;
	long long x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
int main()
{
    long long i,j,k,l,n,m,t,r;
    long long lf,kf,mf,mi,ki;
    scanf("%lld%lld",&n,&r);
    if(n==r)
    printf("1\n");
    else if(n<r)
    printf("-1\n");
    else
    {
    l=n-1;
    k=r-1;
    m=l-k;
    lf=kf=mf=1;
    for(i=1;i<=l;i++)
    {
               lf=(lf*i)%10000007;
    }
    for(i=1;i<=k;i++)
    {
                    kf=(kf*i)%10000007;
    }
    for(i=1;i<=m;i++)
    {
                     mf=(mf*i)%10000007;
    }
    mi=mul_inv(mf,10000007);
    ki=mul_inv(kf,10000007);
    t=(lf*ki)%10000007;
    t=(t*mi)%10000007;
    printf("%lld\n",t);
}

    return 0;
}
