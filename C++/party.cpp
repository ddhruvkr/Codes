# include <stdio.h>
int max(int a, int b) {
	if(a>=b)return a;
	else return b;
}
int cost, fun, dp[101][505];

int main() {
	int v, n, w, i, best,k;
	scanf("%d%d", &v, &n);
	while(v!=0 || n!=0) {
		if(v==0 || n==0)printf("0 0\n");
		else {
			for(i = 1; i <= n; i++) {
				scanf("%d%d", &cost, &fun);
				for(w = 1; w <= v; w++) {
					if(cost > w) dp[i][w] = dp[i-1][w];
					else dp[i][w] = max(dp[i-1][w], dp[i-1][w-cost] + fun);
				}
			}
			for(w = v, best = dp[n][v]; w; w--)
				if(dp[n][w] < best)
					break;
			printf("%d %d\n", w + 1, dp[n][v]);
			}
		scanf("%d%d", &v, &n);
	}
	return 0;
}
