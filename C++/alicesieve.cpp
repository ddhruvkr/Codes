# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &n);
		if(n%2==0)printf("%d\n",n/2);
		else printf("%d\n" , n/2+1);
	}
	getch();
	return 0;
}
