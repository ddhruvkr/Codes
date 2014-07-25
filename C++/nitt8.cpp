# include <stdio.h>
int main() {
	int t, a, b, n, i;
	long long max, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		long long arr[n];
		a = 0;
		b = n-1;
		ans = 0;
		for(i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		while(a != b) {
			if(arr[a]  > arr[b]) {
				max = arr[b] * (b - a);
				b--;
			}
			else {
				max = arr[a] * (b - a);
				a++;
			}
			if(ans < max)ans = max;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
