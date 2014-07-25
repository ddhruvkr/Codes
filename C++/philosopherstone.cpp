#include <stdio.h>

#define INF -1

int dp[128][128];

int max(int a, int b) {
	return (a <= b ? b : a);
}

int main() {
	//printf("%d" , INF);
	int m, n, i, j ,t , ans;
	scanf("%d" ,&t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++) {
			for(j = 1; j <= m; j++)
				scanf("%d", &dp[i][j]);
				dp[i][0] = dp[i][j] = INF;
		}
		for(i = 1; i < n; i++)
			for(j = 1; j <= m; j++)
				dp[i][j] += max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1]));
		for(i = n-1, ans = INF, j = 1; j <= m; j++)
			ans = max(ans, dp[i][j]);
		printf("%d\n", ans);
	}
	return 0;
}
