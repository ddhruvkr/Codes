# include <cstdio>

using namespace std;
int main()
{
	int t,i,pr,pr1,j,n,k,start,end,q,max,c1,br=0;
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &n);
		scanf("%d" , &k);
		int a[n],c[n],b[n];
		for(i=0;i<n;i++){scanf("%d" , &a[i]);c[i]=0;b[i]=a[i];}
		i=0;
		max=c[0];c1=0;
		br=0;
		while(br!=1 && i<n) {
			if(a[i]>k){a[i]=0;i++;}
			else br=1;
		}
		start=i;
		end=i+1;
		q=0;
		while(end<n) {

		if(a[start]+a[end]<=k) {
			a[start]=a[start]+a[end];
			q++;
			end++;
		}
		else {
			pr=a[start];
			pr1=b[start];
			c[start]=q+1;
			if(c[start]>max){max=c[start];c1=start;}
			else if(c[start]==max)if(a[start]<=a[c1]){max=c[start];c1=start;}
			start++;
			a[start]=pr-pr1;
			q--;
			if(start==end) {
				i=start;br=0;
                while(br!=1) {
					if(a[i]>k)i++;
					else br=1;
				}
				start=i;
				a[start]=b[start];
				end=i+1;
				q=0;
			}
		}
		c[start]=q+1;
		if(c[start]>max){max=c[start];c1=start;}
		else if(c[start]==max)if(a[start]<=a[c1]){max=c[start];c1=start;}
	}

		printf("%d %d\n" , a[c1],max);
	}

	return 0;
}
