# include <stdio.h>
# include <conio.h>
# include <math.h>
int main()
{
	int q;
	long m,n,i,t,j,s;
	scanf("%d" , &t);
	for(q=0;q<t;q++) {
		scanf("%ld" , &m);
		scanf("%ld" , &n);
		s = n+1;
		char c[s];
		for(i=1;i<=n;i++)c[i] = '1';
		c[1] = '0';
		if(n>=4)
		for(i=4;i<=n;i+=2)c[i] = '0';
		for(j=3;j<sqrt(n);j++) {
			if(c[j] == '1') {
				s = 0;
				for(i=2;i<sqrt(j);i++)if(j%i==0)s++;
				if(s==0) {
					if(n>=j*j) {
						for(i=j*j;i<=n;i+=j)c[i] = '0';
					}
				}
				else c[j] = '0';
			}
		}
		for(i=m;i<=n;i++)if(c[i] == '1')printf("%d " , i);
		printf("\n");
	}
	getch();
	return 0;
}
