# include <cstdio>
# include <conio.h>
using namespace std;
int josephus(int n, int k)
{
   int r = 0;
   int i = 2;
   while (i <= n) {
     	r = (r + k) % i;
     	k++;
     	printf("%d ",r);
     	i+= 1;
	}
	printf("\n");
   return r+1;
}
int main()
{
	printf("%d\n",josephus(6,1));
	getch();
	return 0;
}
