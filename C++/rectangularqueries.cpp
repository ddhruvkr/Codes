//refer diary for reason
#include <cstdio>

using namespace std;

int a[501][501][11] = {0};

int main()
{
    int i, j, k, n, m, d;
    int x1, x2, y1, y2;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j][0]);
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= 10; k++) {
                a[i][j][k] = a[i-1][j][k] + a[i][j-1][k] - a[i-1][j-1][k];
                if (a[i][j][0] == k) {
                   a[i][j][k]++;
                }
            }
        }
    }
    scanf("%d", &m);
    while (m--) {
        d = k = 0;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (i = 1; i <= 10; i++) {
            d = a[x2][y2][i] - a[x2][y1-1][i] - a[x1-1][y2][i] + a[x1-1][y1-1][i];
            if (d > 0) {
                k++;
			}
        }
        printf("%d\n", k);
    }
    return 0;
}
