#include <cstdio>
#include <algorithm>

using namespace std;

//#define INF 1000000000

int main() {
	int t, n, i, j, max;
	int dp[1005], h[505], k[505];
	
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		max = 0;
		for(i = 1; i <= n; i++) {
			scanf("%d", &h[i]);
			if(max < h[i])max = h[i];
		}
        for(i = 1; i <= n; i++)scanf("%d", &k[i]);
        /*dp[0][0] = 0;
        for(j = 1; j <= 2*max; j++)dp[0][j] = 1000000000;
        for(i = 1; i <= n; i++) {
			for(j = 0; j <= 2*max; j++) {
				dp[i][j] = dp[i-1][j];
				if(j >= k[i])dp[i][j] = min(dp[i][j], 1 + dp[i][j-k[i]]);
			}
        }
        max = 0;
        for(i = 0; i <= 4; i++ ){
			for(j =0 ;j < 9; j++)printf("%d\t", dp[i][j]);
			printf("\n");
        }
        for(i = 1; i <= n; i++) {
			max = max + dp[n][2*h[i]];
        }*/
		dp[0] = 0;
		for(j = 1; j <= 2*max; j++)dp[j] = 1000000000;
        for(i = 1; i <= n; i++) {
			for(j = k[i]; j <= 2*max; j++) {
				if(dp[j] > 1 + dp[j-k[i]])dp[j] = 1 + dp[j-k[i]];
			}
        }
        max = 0;
        for(i = 1; i <= n; i++) {
			max = max + dp[2*h[i]];
        }
        printf("%d\n", max);
	}
	return 0;
}
