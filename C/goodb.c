# include <stdio.h>

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

long long fact(int l)
{
	long long lf=1;
	int i;
    for(i=1;i<=l;i++)
    {
               lf=(lf*i)%1000000007;
    }
    return lf;
}
int main()
{
	int n,w,t,r;
	scanf("%d%d%d%d",&n,&w,&t,&r);
    long long nfact=fact(n);
    long long wfact=fact(w);
    //long long rfact=fact(r);
    long long tfact=fact(t);
    long long nwfact=fact(n-w);
    long long ntfact=fact(n-w-t);
    //long long nrfact=fact(n-r);
    wfact=mul_inv(wfact,1000000007);
    //rfact=mul_inv(rfact,1000000007);
    tfact=mul_inv(tfact,1000000007);
    long long nw1fact=mul_inv(nwfact,1000000007);
    //nrfact=mul_inv(nrfact,1000000007);
    ntfact=mul_inv(ntfact,1000000007);
    long long t1=(nfact*wfact)%1000000007;
    t1=(t1*nw1fact)%1000000007;
    long long t2=(nwfact*tfact)%1000000007;
    t2=(t2*ntfact)%1000000007;
    //long long t3=(nfact*tfact)%1000000007;
    //t3=(t3*ntfact)%1000000007;
	t1=t1*t2;
	t1=t1%1000000007;
	//t1=t1+t3;
	//t1=t1%1000000007;
	printf("%lld\n",t1);
	return 0;
}
