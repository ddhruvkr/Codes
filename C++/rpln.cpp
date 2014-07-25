# include <stdio.h>
int main() {
	int t, count = 0;
	long long int n, q, i, j, a, b, d;
	scanf("%d" , &t);
	while(t--) {
		count++;
		scanf("%lld%lld", &n, &q);
		long long int arr[n + 1];
		for(i = 1; i <= n; i++)scanf("%lld" , &arr[i]);
		printf("Scenario #%d:\n", count);
		printf("\n");
		while(q--) {
			scanf("%lld%lld" , &a , &b);
			d = arr[a];
			for(i = a + 1; i <= b; i++) {
				if(a > arr[i])d = arr[i];
			}
			printf("%lld\n", d);
		}
	}
	return 0;
}
