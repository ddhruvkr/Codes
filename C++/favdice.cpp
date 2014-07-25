# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int i,n,t;
	float s=0.00 , d;
	scanf("%d" , &t);
	while(t--) {
		s = 0.00;
		scanf("%d" , &n);
		for(i=n;i>0;i--){d = (float)n/i;s = s + d;}
		printf("%.2f\n" , s);
	}
	getch();
	return 0;
}
