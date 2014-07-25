# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int t;
	long long int m,n;
	scanf("%d" , &t);
	while(t--) {
		scanf("%lld%lld",&n,&m);
		if(n==m && n%2!=0 && m%2!=0)printf("R\n");
		else if(n==m && n%2==0 && m%2==0)printf("L\n");
		else if(n==1)printf("R\n");
		else if(m==1)printf("D\n");
		else if(n<m)printf("L\n");
		else if(n>m && n%2!=0)printf("U\n");
		else printf("D\n");
	}
	getch();
	return 0;
}
