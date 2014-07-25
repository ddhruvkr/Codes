# include <stdio.h>
# include <conio.h>
int main()
{
	int q=0,m=0,i,A,D,min,t;
	int a[11] , d[11];
	scanf("%d %d" , &A , &D);
	if( A == 0 && D == 0)q=1;
	while(q != 1) {
		for(i=0;i<11;i++)a[i] = -1;
		for(i=0;i<11;i++)d[i] = -1;
		for(i=0;i<A;i++)scanf("%d " , &a[i]);
        for(i=0;i<A;i++)printf("%d " , a[i]);
		for(i=0;i<D;i++)scanf("%d " , &d[i]);
        for(i=0;i<D;i++)scanf("%d " , d[i]);
		i=1;
		min = a[0];
		while(a[i]!=-1) {
			if(min > a[i])min = a[i];
			i++;
		}
		t = 0;
		m = 0;
		for(i=0;i<D;i++) {
			if(min >= d[i])t++;
			if(t==2) {
				m=1;
				break;
			}
		}
		printf("dhruv\n");
		if(m==1)printf("NO\n");
		else printf("YES\n");
		scanf("%d %d" , &A , &D);
		if( A == 0 && D == 0)q=1;
	}
	
}
