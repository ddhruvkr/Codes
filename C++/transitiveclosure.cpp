# include <cstdio>
using namespace std;
int main()
{
	int q=0,i,j,k,t,n,f,s,br,count,m;
	int a[10000][2];
	scanf("%d",&t);
	while(t--) {
		count=0;
		q++;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(j!=i && a[j][0]==a[i][1]) {
					f=a[i][0];s=a[j][1];
					br=0;
					for(k=0;k<n;k++) {
						if( a[k][0]==f && a[k][1]==s) {
							br=1;k=n;
						}
					}
					if(br==0){a[n][0]=f;a[n][1]=s;n++;count++;}
				}
			}
		}
		printf("Case #%d: %d\n",q,count);
	}
	return 0;
}
