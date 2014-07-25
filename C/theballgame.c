# include <stdio.h>
# include <conio.h>
int main()
{
	double i,n;
	int t;
	scanf("%d" , &t);
	while(t--) {
		scanf("%lf" , &n);
		i = (1/n)*(1/(n+1)) + (n-1)/n;
		printf("%.8lf\n" , i);
	}
	getch();
	return 0;
}
