#include <cstdio>
#include <cstring>

using namespace std;

int p[100][100], c[100], sum[100][100];
int process(int a, int b) {
	int d, ans, i;
	if(a == b)return 0;
	if(a == b - 1)return c[a] * c[b];
	d = p[a][b];
	if(d == -1) {
		for(i = a; i < b; i++) {
			ans = sum[a][i] * sum[i + 1][b] + process(a, i) + process(i + 1, b);
			if(d == -1 || ans < d) {
				d = ans;
				p[a][b] = ans;
			}
		}
	}
	return d;
}
int main() {
	int n, i, j;
	while(scanf("%d", &n) == 1) {
		for(i = 0; i < n; i++ ) {
			scanf("%d", &c[i]);
			sum[i][i] = c[i];
		}
		for(i = 0; i < n; i++) {
			for(j = i + 1; j < n; j++) {
				sum[i][j] = (sum[i][j - 1] + c[j]) % 100;
			}
		}
		memset(p, -1, sizeof(p));
		printf("%d\n", process(0, n - 1));
	}
}
