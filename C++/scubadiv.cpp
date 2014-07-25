#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;
int x, vo, vn, n;

int minf(int a, int b) {
	if(a > b)return b;
	else return a;
}

int a[1024][22][80], b[1024][22][80];
int volo[1024], voln[1024], w[1024];
int solve(int c, int ox, int ni) {
	if(ox >= vo && ni >= vn)return 0;
	if(c == n)return INF;
	if(ox >= vo)ox = vo;
	if(ni >= vn)ni = vn;
	if(b[c][ox][ni] == x)return a[c][ox][ni];
	b[c][ox][ni] = x;
	return a[c][ox][ni] = min(solve(c + 1, ox, ni), solve(c + 1, ox + volo[c], ni + voln[c]) + w[c]);
}
int main() {
	int i, k;
	scanf("%d", &k);
	for(x = 1; x <= k; x++) {
		//memset(dp, 9999999, sizeof(dp));
		scanf("%d%d%d", &vo, &vn, &n);
		for(i = 0; i < n; i++) {
			scanf("%d%d%d", &volo[i], &voln[i], &w[i]);
		}
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}

/*#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1024;
const int INF = 0x3f3f3f3f;

int N, O, n, test, cs;
int nitro[MAX], oxi[MAX], w[MAX];
int dp[MAX][22][80], fl[MAX][22][80];

int solve(int i, int co, int cn) {
	if(co >= O && cn >= N) return 0; if(i == n) return INF;
	if(co >= O) co = O; if(cn >= N) cn = N;
	if(fl[i][co][cn] == cs) return dp[i][co][cn]; fl[i][co][cn] = cs;
	return dp[i][co][cn] = min(solve(i+1, co, cn), solve(i+1, co + oxi[i], cn + nitro[i]) + w[i]);
}

int main() {
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %d", &O, &N, &n);
		for(int i = 0; i < n; i++) scanf("%d %d %d", &oxi[i], &nitro[i], &w[i]);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int need1, need2, N;
int vol1[2000], vol2[2000], weight[2000];

int best[80][80], next[80][80];

int solve()
{
	memset(best, 0x3f, sizeof(best));
	best[0][0] = 0;

	for (int i = 0; i < N; i++) {
		memcpy(next, best, sizeof(best));
		for (int a = 0; a <= need1; a++)
			for (int b = 0; b <= need2; b++)
				next[min(need1, a + vol1[i])][min(need2, b + vol2[i])] <?= best[a][b] + weight[i];
		memcpy(best, next, sizeof(best));
	}

	return best[need1][need2];
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int cs = 1; cs <= T; cs++) {
		scanf("%d %d %d", &need1, &need2, &N);
		for (int i = 0; i < N; i++)
			scanf("%d %d %d", &vol1[i], &vol2[i], &weight[i]);
		printf("%d\n", solve());
	}
}*/
