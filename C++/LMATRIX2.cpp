#include <stdio.h>
#include <conio.h>

int main() {
	int n, m, i, j, x, y, s, max, cnt = 0, z;
	int p[100][100], d[100][100], a[100][100], e[100][100], x1[10000], x2[10000], y1[10000], y2[10000], k[10000], c[11];
	scanf("%d%d", &n , &m);
	for(i = 0; i < n; i++)for(j = 0; j < m; j++)scanf("%d", &p[i][j]);
	for(i = 0; i < n; i++)for(j = 0; j < m; j++)scanf("%d", &a[i][j]);
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(a[i][j] != 0) {
				d[i][j] = a[i][j] % p[i][j];
				e[i][j] = p[i][j] - d[i][j];
			}
			else  {
				e[i][j] = -99;
			}
		}
	}
	for(i = 0; i < 11; i++)c[i] = 0;
	for(i = 0; i < n; i++) {
		for(j = 0 ; j < m; j++) {
			if(e[i][j] != -99)
			c[e[i][j]]++;
			else c[10]++;
		}
	}
	max = 0;
	for(i = 0; i <= 10; i++) {
		if(max < c[i])max = i;
	}
	if(max != 10) {
		x1[cnt] = 0;
		x2[cnt] = n-1;
		y1[cnt] = 0;
		y2[cnt] = m-1;
		k[cnt] = max;
		cnt++;
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				a[i][j] = (max + a[i][j]) % p[i][j];
			}
		}
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(a[i][j] != 0) {
				z = p[i][j] - a[i][j];
				a[i][j] = (z + a[i][j]) % p[i][j];
				x1[cnt] = i;
				x2[cnt] = i;
				y1[cnt] = j;
				y2[cnt] = j;
				k[cnt] = z;
				cnt++;
			}
		}
	}
	/*		if(a[i][j] != 0) {
				a[i][j] = a[i][j]
			}
		}
	}
		max = 0;
		for(j = 0; j < 10; j++) {
			if(max < c[j])max = j;
		}
		x1[cnt] = x2[cnt] = i;
		y1[cnt] = 0;
		y2[cnt] = m-1;
		k[cnt] = max;
		cnt++;
		for(j = 0; j < m; j++)a[i][j] = a[i][j] - max;
		for(j = 0; j < m; j++) {
			if(a[i][j] != 0) {
				a[i][j] = a[i][j] % p[i][j];
				e[i][j] = p[i][j] - a[i][j];
				a[i][j] = a[i][j] - e[i][j];
				x1[cnt] = x2[cnt] = i;
				y1[cnt] = j;
				y2[cnt] = j;
				k[cnt] = e[i][j];
				cnt++;
			}
		}
	}
	
	*/
	//for(i = 0; i < n; i++)for(j = 0; j < m; j++)printf("%d ", e[i][j]);
	//printf("\n");
	
	printf("%d\n", cnt);
	for(i = 0; i < cnt; i++) {
		printf("%d %d %d %d %d\n", x1[i] + 1, y1[i] + 1, x2[i] + 1, y2[i] + 1, k[i]);
	}
	getch();
	return 0;
}
