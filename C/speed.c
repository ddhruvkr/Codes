/*# include <stdio.h>
# include <conio.h>
# include <math.h>
int main()
{
	int t,n,m;
	scanf("%d" , &t);
	while(t--) {
		scanf("%d%d" , &n , &m);
		max=m;min=n;
		if(n>m){max=n;min=m;}
		if(n==m || (-1*m)==n)printf("2\n");
		if(max>0 && min>0)printf("%d\n" , (max-min)/__gcd(min,max));
		else if(n<0 || m<0)printf("%d\n" , abs(n-m));
		else if(n>m && n%m!=0 || m>n && m%n!=0)printf("%d\n"  , abs(n-m)/__gcd());
		else if(n>m && n%m==0)printf("%d\n" , (n-m)/m);
		else if(m>n && m%n==0)printf("%d\n" , (m-n)/n);
	}
	getch();
	return 0;
}*/
#include<stdio.h>
//#include<algorithm>
//#include<iostream>

//using namespace std;

int gcd(int a, int b)
{
  int c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int ans;
		if(a > b)
			ans = a - b;
		else
			ans = b - a;
		if (a < 0) a = a * (-1);
		if (b < 0) b = b*(-1);
		ans = ans/gcd(a,b);
		printf("%d\n",ans);
	}
	return 0;
}
