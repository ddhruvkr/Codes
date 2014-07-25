#include <stdio.h>

int main() {
	int n, i, j, cnt, nq, q;
	int a[51], dp[51][51];
	scanf("%d", &n);
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	for(i = 0; i < n; i++)dp[i][i] = a[i];
	for(i = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			if(a[j] <= dp[i][j-1])dp[i][j] = a[j];
			else dp[i][j] = dp[i][j-1];
		}
	}
	scanf("%d", &nq);
	while(nq--) {
		scanf("%d", &q);
		cnt = 0;
		for(i = 0; i < n; i++) {
			for(j = i; j < n; j++) {
				if(dp[i][j] == q)cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
