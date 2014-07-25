#include <stdio.h>
#include <conio.h>

long int josephus(long int n, long int k)
{
  	if (n == 1)
	return 1;
    `else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1;
    //if((n-1)==0)
   //return 1;
   //if((n % 2)==0)
   //return ((josephus(n/2,k)*2)-1);
   //return ((josephus((n-1)/2,k)*2)+1);
}

int main()
{
  long int N,D;
  scanf("%ld %ld" , &N , &D);
  while(N!=0 && D!=0) {
		printf("%ld %ld %ld\n", N , D , josephus(N , D));
		scanf("%ld %ld" , &N , &D);
	}
	getch();
  return 0;
}
