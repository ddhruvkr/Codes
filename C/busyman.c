# include <stdio.h>
int main()
{
	int n,j,s;
	scanf("%d",&n);
	while(n!=-1) {
		s=1;
		j=1;
		while(s<n) {
			s=s+6*j;
			j++;
		}
		if(s==n)printf("Y\n");
		else printf("N\n");
		scanf("%d",&n);
	}
	return 0;
}
