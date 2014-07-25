#include <cstdio>
#include <algorithm>

using namespace std;

long long a[100003];
long long dp1[100003],dp2[100003];

int main() {
	int t;
	long long n, k, i, maxm, cmax, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld", &n, &k);
		for(i = 0; i < n; i++)scanf("%lld", &a[i]);
		maxm = cmax = dp1[0] = a[0];
		for(i = 1; i < n; i++) {
			cmax = max(cmax + a[i], a[i]);
			dp1[i] = maxm = max(maxm, cmax);
		}
		maxm = cmax = dp2[n - 1] = a[n - 1];
		for(i = n - 2; i >= 0; i--) {
			cmax = max(cmax + a[i], a[i]);
			dp2[i] = maxm = max(maxm, cmax);
		}
		ans = dp1[0] + dp2[k + 1];
		for(i = 1; i < n - 1 - k; i++) {
			ans = max(ans, dp1[i] + dp2[i + k + 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
