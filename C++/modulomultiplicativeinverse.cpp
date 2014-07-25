#include <stdio.h>
# include <conio.h>
# include <math.h>
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
long long D=0,X=0,Y=0,d=0,x=0,y=0;
long long mulinv(long long a,long long b)
{
	//long long D=0,X=0,Y=0,d=0,x=0,y=0;
	if(b==0)return (a,1,0);
	else {
        D,X,Y=mulinv(b,a%b);
        printf("%lld %lld %lld\n" , D,X,Y);
        d=D;
		x=Y;
		y=X-(a/b)*Y;
        return d;
        return x;
        return y;
	}
}
int main()
{
	long long int d,y,x;
	//d=mul_inv(4,11);
	//s=mul_inv(3,11);
	printf("%lld\n" , mul_inv(3,11));
	(d,x,y)=mulinv(3,11);
	printf("%lld\n" , x);
	getch();
	return 0;
}
