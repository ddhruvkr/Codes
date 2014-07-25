# include <stdio.h>
int main()
{
	int q=0,n,t,p,i,j,s,a,b,c;
	scanf("%d",&t);
	while(t--) {
		q++;
		a=0;
		b=0;
		c=0;
		scanf("%d%d",&n,&p);
		int arr[n][p];
		for(i=0;i<n;i++)for(j=0;j<p;j++)scanf("%d",&arr[i][j]);
		for(i=0;i<n;i++) {
			s=0;
			for(j=0;j<p;j++) {
				s=s+arr[i][j];
			}
			if(s==p)c=1;
			if(s==0)b=1;
			if(s==0 && s==p)i=n;
		}
		for(j=0;j<p;j++) {
			s=0;
			for(i=0;i<n;i++) {
				s=s+arr[i][j];
			}
			if(s==0){a=1;j=p;}
		}
		s=0;
		if(a==0)s=4;
		if(b==0)s=s+2;
		if(c==0)s=s+1;
		printf("Case %d: %d\n",q,s);
	}
	return 0;
}
