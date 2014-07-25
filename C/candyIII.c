# include <stdio.h>
# include <conio.h>
int main()
{
	long long N,i,d=0,j,T,s;
	scanf("%lld" , &T);
	printf("\n");
	for(j=0;j<T;j++)
	{
		d=0;
        scanf("%lld" , &N);
		for(i=0;i<N;i++)
		{
			scanf("%lld" , &s);
			d = d + s%N;
		}
		if(d%N == 0)printf("YES\n");
		else printf("NO\n");
	}
	getch();
	return 0;
}
