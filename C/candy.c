# include <stdio.h>
# include <conio.h>
int main()
{
	int n,i,s=0,d,t;
	int a[10001];
	scanf("%d" , &n);
	while(n!=-1)
	{
		t=0;
		s=0;
		for(i=0;i<10001;i++)a[i] = 0;
		for(i=0;i<n;i++)scanf("%d" , &a[i]);
		i=0;
		while(a[i]!=0)
		{
			s = s + a[i];
			i++;
		}
		if(s%n == 0) {
			d = s/n;
			for(i=0;i<n;i++) {
				if(a[i]<d)t = t + d - a[i];
			}
			printf("%d\n" , t);
		}
		else printf("-1\n");
		scanf("%d" , &n);
	}
	getch();
	return 0;
}
