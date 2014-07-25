/*# include <cstdio>
using namespace std;
long long int max(long long int a, long long int b) {
	if(a >= b)return a;
	else return b;
}
int main() {
	long long int n, v, i, maxhere, maxsofar, j, k;
	scanf("%lld%lld", &n, &v);
	long long int l[n];
	for(i = 0;i < n; i++) {
		scanf("%lld", &l[i]);
	}
	maxhere=maxsofar=i=j=k=0;
	while(i<=n-1) {
    	if(maxhere+l[i]<v) {
        	maxhere=max(0,maxhere+l[i]);
        	i+=1;
		}
    	else if(maxhere+l[i]==v) {
        	maxsofar=maxhere+l[i];
        	break;
		}
    	else {
        	maxsofar=max(maxhere,maxsofar);
        	maxhere=maxhere-l[k];
        	k+=1;
		}
	}
	printf("%lld\n", maxsofar);
	return 0;
}*/


# include <cstdio>
using namespace std;
int main()
{
	long long int i, pr, pr1, n, k, max;
	int start, end, br = 0;
		scanf("%lld" , &n);
		scanf("%lld" , &k);
		long long int a[n],b[n];
		for(i = 0; i < n; i++){
			scanf("%lld" , &a[i]);
			b[i]=a[i];
		}
		i=0;
		br=0;
		start = 0;
		end = 1;
		while(end < n) {
			if(a[start] == k) {
				printf("%lld\n", k);
				return 0;
			}
			if(a[start] + a[end] == k) {
                printf("%lld\n", k);
				return 0;
			}
			if(a[start] + a[end] <= k) {
				a[start] = a[start] + a[end];
				end++;
			}
			else {
				pr = a[start];
				pr1 = b[start];
				start++;
				a[start] = pr - pr1;
				if(start == end) {
					i=start;
					br=0;
                	while(br != 1) {
						if(a[i] >= k)i++;
						else br=1;
					}
					start=i;
					a[start]=b[start];
					end=i+1;
				}
			}
		}
		max = a[0];
		for(i = 1; i < n; i++)
		if(a[i] > max)max=a[i];
		printf("%lld\n", max);
	return 0;
}
