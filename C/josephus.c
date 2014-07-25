#include <cstdio>
#include <conio.h>
using namespace std;

long int josephus(long int n, long int k)
{
   if((n-1)==0)
   return 1;
   if((n % 2)==0)
   return ((josephus(n/2,2)*2)-1);
   return ((josephus((n-1)/2,2)*2)+1);
}

long int power(long int n , long int k)
{
	long int s=1;
	while(k!=0) {
		s = s*n;
		k--;
	}
	return s;
}

int main()
{
    char a[4];
	long int n;
	scanf("%s" , &a);
	int m = 1;
	if((a[0] == '0') && (a[1] == '0') && (a[3] == '0'))m=0;
	while (m==1)
	{
		n = ((10 * ((long int)(a[0])-48) + ((long int)(a[1])-48)) * power(10 , ((long int)(a[3])-48)));
        printf("%ld\n", josephus(n, 2));
		scanf("%s" , &a);
	    if((a[0] == '0') && (a[1] == '0') && (a[3] == '0'))m=0;
	}
    getch();
    return 0;
}
