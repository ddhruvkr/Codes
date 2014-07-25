# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int t,n,i,j,ans;
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &n);
		 i = n - 2;
         j = i / 2 + 1;
        if (i % 2 == 0) {
            i = n - 3;
            j = j - 1;
        }
        ans = (j%n) * ((1 + i)%n);
        ans /= 2;
        ans = ans % n;
		printf("%d\n" , ans);
	}
	getch();
	return 0;
}
