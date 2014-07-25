#include <cstdio>
#include <conio.h>
#include <stack>

using namespace std;

int main() {
    stack <int> s;
	int n, m, k, i, j, x, y, tp, z;
	scanf("%d%d%d", &n, &m, &k);
	int inp[n+1][m+1], cnt[n+1][m+1], dp[n+1][m+1];
	for(i = 0; i <= n; i++)
	for(j = 0; j <= m; j++)inp[i][j] = 1;
	for(i = 0; i < k; i++) {
		scanf("%d%d", &x, &y);
		inp[x][y] = 0;
	}
	for(i = 1; i <= m; i++)cnt[1][i] = inp[1][i];
	for(i = 2; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(inp[i][j] != 0)cnt[i][j] = inp[i][j] + cnt[i-1][j];
			else cnt[i][j] = 0;
    /*for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++)printf("%d ", cnt[i][j]);
		printf("\n");
	}*/
	for(i = 1; i <= n; i++) {
		j = 1;z = 0;
		while(j <= m) {
			if(s.empty() || cnt[i][s.top()] <= cnt[i][j]) {
				if(cnt[i][j] == 0) {
					dp[i][j++] = 0;
					z = j;
				}
				else s.push(j++);
			}
			else {
				tp = s.top();
				s.pop();
				dp[i][tp] = (s.empty() ? j-1-z : j - s.top());
				//if(dp[i][tp] != 0)dp[i][tp] /= (cnt[i][tp]+1);
			}
		}
		while(s.empty() == false) {
            tp = s.top();
        	s.pop();
        	//if(i == 1)printf("%dff", j);
        		dp[i][tp] = (s.empty() ? j-1-z : j - s.top() - 1);
        		//if(dp[i][tp] != 0)dp[i][tp] /= cnt[i][tp];
		}
	}
	/*for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++)printf("%d ", cnt[i][j]);
		printf("\n");
	}*/
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++)printf("%d ", dp[i][j]);
		printf("\n");
	}
	
	getch();
	return 0;
}
