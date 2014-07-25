#include <stdio.h>
#include <conio.h>
 int main() {
		int p;
        while(scanf("%d", &p) == 1) {
			//scanf("%d", &p);
			int a[105];
			int i, j, k, l, q, w;
			for(i = 0; i < p; i++)
			scanf("%d", &a[i]);
			int m[p + 1][p + 1];
			int n[p + 1][p + 1];
			for(i = 1; i < p + 1; i++) {
				m[i][i] = 0;
				n[i][i] = a[i - 1];
			}
			for(l = 2; l <= p; l++) {
				for(i = 1; i <= (p - l + 1); i++) {
					j = i + l - 1;
					m[i][j] = 999999999;
					for(k = i; k <= j - 1; k++) {
						q = n[i][k] * n[k + 1][j] + m[i][k] + m[k + 1][j];
						w = (n[i][k] + n[k + 1][j]) % 100;
						if(q < m[i][j]) {
							m[i][j] = q;
							n[i][j] = w;
						}
					}
				}
			}
			printf("%d\n", m[1][p]);
		}
		getch();
		return 0;
 }
