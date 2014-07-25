# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int t,n,i,s,j,pr;
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &n);
		int a[n+1][n+1];
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				scanf("%d" , &a[i][j]);
			}
		}
		for(i=1;i<=n;i++) {
			for(j=i+1;j<=n;j++) {
				s=1;pr=1;
				while(s!=n+1) {
					if(s!=i && s!=j) {
						if(a[i][j]==a[i][s] + a[s][j]){pr=0;break;}
					}
					s++;
				}
			if(pr==1)printf("%d %d\n" , i , j);
			}
		}
	}
	getch();
	return 0;
}
