# include <cstdio>
# include <list>
using namespace std;
long long arr[100000];
long long a[20];
long long m,n;

void pred(long long stop) {
	long long count=0;
	list <long long> q;
	while(stop!=1) {
		count++;
		q.push_back(arr[stop]);
		stop=(stop+n-2)/n;
	}
	printf("%lld\n",count);
	printf("1 ");
	while(!q.empty()) {
		printf("%lld ",q.back());
		q.pop_back();
	}
	printf("\n");
}
void heap() {
	arr[1]=1;
	long long start,stop,i,k,j;
	start=2;
	stop=n+2;
	k=stop-1;
	while(start != stop) {
		for (i = start;i <= k;i++) {
			for(j=0;j<n;j++) {
				if(arr[i]*a[j]<=m){
					arr[stop]=a[j]*arr[i];
					stop++;
				}
				if(arr[stop-1]==m){
					pred(stop-1);
					return;
				}
			}
		}
		start=k+1;
		k=stop-1;
	}
	printf("-1\n");
}
int main() {
	int k;
	long long i;
	while(scanf("%lld %lld",&n,&m) != EOF){
		//scanf("%lld%lld",&m,&n);
		for(i=0;i<n;i++)scanf("%lld",&a[i]);
		for(i=0;i<n;i++)arr[i+2]=a[i];
		heap();
	}
	return 0;
}
