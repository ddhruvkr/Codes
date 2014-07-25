#include <cstdio>

using namespace std;

int main() {
	int t, n, m, a, b, ind, max, i , j, x, min, q, stop;
	int adj[105][105], cnt[105], pre[105];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++) {
			cnt[i] = 0;
			for(j = 1; j <= n; j++) {
				adj[i][j] = 0;
			}
		}
		for(i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			if(adj[a][b] != 1 && a != b) {
				adj[a][b] = 1;
				adj[b][a] = 1;
				cnt[a]++;
				cnt[b]++;
			}
		}
		for(i = 1; i <= n; i++)if(cnt[i] == 0)n = 3;
		if(n%2 != 0)printf("NO\n");
		else {
			x = 0;
            for(i = 1; i <= n; i++) {
				if(cnt[i] == 1)x++;
			}
			stop = 0;
			while(x != n) {
				max = 0;
				min = 101;
				for(i = 1; i <= n; i++) {
					if(cnt[i] < min) {
						min = cnt[i];
						j = i;
					}
				}
				for(i = 1; i <= n; i++) {
					if(adj[j][i]) {
						if(cnt[i] > max) {
							max = cnt[i];
							ind = i;
						}
					}
				}
				for(i = 1; i <= n; i++)pre[i] = cnt[i];
				cnt[ind] = 999;
				cnt[j] = 999;
				x = 0;
				for(i = 1; i <= n; i++)if(i != ind && i != j) {
					if(adj[ind][i] == 1) {
						cnt[i]--;
						adj[ind][i] = 0;
						adj[i][ind] = 0;
						if(cnt[i] == 0) {
							x = n;
							stop = 1;
						}
					}
					if(adj[j][i] == 1) {
						cnt[i]--;
						adj[j][i] = 0;
						adj[i][j] = 0;
						if(cnt[i] == 0) {
							x = n;
							stop = 1;
						}
					}
				}
				if(x != n) {
					x = 0;
					for(i = 1; i <= n; i++) {
						if(pre[i] == cnt[i]) {
							x++;
						}
						if(x == n)stop = 1;
					}
				}
				if(x != n) {
					x = 0;
                	for(i = 1; i <= n; i++) {
						if(cnt[i] == 999)x++;
					}
				}
			}
			if(stop == 0)
			printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
