# include <stdio.h>
# include <math.h>
int powerof2(long long n) {
	return n && !(n & (n-1));
}
int main()
{
	long long t;
	int br=0;
	scanf("%lld",&t);
	br=powerof2(t);
	if(br==1)printf("TAK\n");
	else printf("NIE\n");
	return 0;
}
