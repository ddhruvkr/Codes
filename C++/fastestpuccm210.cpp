# include <cstdio>
//# include <conio.h>
# include <vector>
using namespace std;
long long square(int i)
{
	long long s=1;
	int j;
	for(j=0;j<2;j++) {
		s=s*i;
		s=s%1000000003;
	}
	return s;
}
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
    vector<long long> v;
	int t,n,i,j;
	long long s,d=1,s1,s2;
	scanf("%d" , &t);
	v.push_back(1);
	for(i=2;i<=1000000;i++) {
		s=square(i);
		s1=square(i+1);
		s2=mul_inv(4,1000000003);
		s=s*s1;
		s=s%1000000003;
		s=s*s2;
		s=s%1000000003;
		d=d+s;
		d=d%1000000003;
		v.push_back(d);
	}
	while(t--) {
		scanf("%d" , &n);
		printf("%lld\n" , v.at(n-1));
	}
	//getch();
	return 0;
}
