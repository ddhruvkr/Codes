#include <stdio.h>

#define gc getchar_unlocked
#define pc putchar_unlocked

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int a[1001], b[1001][1001] ,c[1001][1001], v[1001][1001], max[1001], ind[1001];

void qsort(int left, int right) {

      int i = left, j = right;
      int tmp, tmp1;
      int pivot = max[(left + right) / 2];

      while (i <= j) {
            while (max[i] < pivot)
                  i++;
            while (max[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = max[i];
                  tmp1 = ind[i];
                  max[i] = max[j];
				  ind[i] = ind[j];
                  max[j] = tmp;
				  ind[j] = tmp1;
                  i++;
                  j--;
            }
      };

      if (left < j)
            qsort(left, j);
      if (i < right)
            qsort(i, right);
}

int main()
{
	int t, n, m, k, i, j;
	t = read_int();
	while (t--) {
		n = read_int();
		m = read_int();
		k = read_int();

		for (i = 1; i <= n; i++) a[i] = read_int();
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				scanf("%d", &b[i][j]);
			}
		}

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				c[i][j] = read_int();
			}
		}

		for(i = 1; i <= n; i++) {
			max[i] = 0;
			ind[i] = i;
			for(j = 1; j <= m; j++) {
					v[i][j] = b[i][j] - c[i][j] - b[i][a[i]];
					if(v[i][j] > max[i])max[i] = v[i][j];
			}
		}
		qsort(1, n);
		int x = k;
		int i = n + 1;
		int ans = 0;
		while (x != 0 && i != 1) {
			i--;
			if (max[i] == 0) {
				ans = ans + b[ind[i]][a[ind[i]]];
			}
			else if (max[i] > 0) {
				ans = ans + max[i] + b[ind[i]][a[ind[i]]];
				x--;
			}
		}

		if (i != 1) {
			while (i != 1) {
				i--;
 				ans = ans + b[ind[i]][a[ind[i]]];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
