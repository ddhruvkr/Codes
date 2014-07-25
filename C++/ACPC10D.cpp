# include <cstdio>
using namespace std;
 long long int min(long long int a, long long int b) {
	return a < b ? a : b;
}
int main()
{
	int n,i,q=0;
	scanf("%d",&n);
	while(n!=0) {
		q++;
		long long int arr[n][3];
		for(i=0;i<n;i++)for(j=0;j<3;j++)scanf("%lld",&arr[i][j]);
		arr[0][2]+=arr[0][1];
        arr[1][0]+=arr[0][1];
        arr[1][1]+=min(min(arr[1][0],arr[0][1]),arr[0][2]);
        arr[1][2]+=min(min(arr[1][1],arr[0][1]),arr[0][2]);
		for(i=2;i<n;i++) {
                arr[i][0]+=min(arr[i-1][0],arr[i-1][1]);
                arr[i][1]+=min(min(arr[i][0],arr[i-1][1]),min(arr[i-1][0],arr[i-1][2]));
                arr[i][2]+=min(min(arr[i][1],arr[i-1][1]),arr[i-1][2]);
		}
		printf("%d. %lld\n",q,arr[n-1][1]);
		scanf("%d",&n);
	}
	return 0;
}
