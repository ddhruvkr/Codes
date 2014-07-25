#include <cstdio>
#include <conio.h>
using namespace std;

int main(){
    int T,n;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        int ans = 0;

        for(int i = 2;i <= n;++i)
            ans = (ans + n + 1 - i) % i;

        printf("%d\n",ans + 1);
    }
	getch();
    return 0;
}
/*#include <stdio.h>
#include <conio.h>

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    /*return (josephus(n - 1, k) + k-1) % n + 1;
}

// Driver Program to test above function
int main()
{
  int n;
  scanf("%d" , &n);
  int k = 2;
  printf("The chosen place is %d", josephus(n, k));
  getch();
  return 0;
}*/
/*#include <stdio.h>
#include <conio.h>
// m-th on the reversed kill list; m = 0 is final survivor
int jos(int n, int k, int m) {
	int a;
	for (a = m + 1; a <= n; a++)
		m = (m + k) % a;
	return m;
}

typedef unsigned long long xint;

// same as jos(), useful if n is large and k is not
xint jos_large(xint n, xint k, xint m) {
	if (k <= 1) return n - m - 1;

	xint a = m;
	while (a < n) {
		xint q = (a - m + k - 2) / (k - 1);

		if (a + q > n)	q = n - a;
		else if (!q)	q = 1;

		m = (m + q * k) % (a += q);
	}

	return m;
}
int main(void) {
	xint n, k, i;

	n = 5;
	k = 2;
	printf("n = %llu, k = %llu, final survivor: %d\n", n, k, jos(n, k, 0/*o pe last man,1 pe second last...));*/

	/*n = 9876543210987654321ULL;
	k = 12031;
	printf("n = %llu, k = %llu, three survivors:", n, k);

	for (i = 3; i--; )
		printf(" %llu", jos_large(n, k, i));
	putchar('\n');
	getch();
	return 0;
}*/
