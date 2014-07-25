# include <stdio.h>
#include <iostream>

using namespace std;
int main() {
	int test, n, i, j, k, g[50][50], best, idx, cnt;
	char str[64];
	scanf("%d", &test);
	while(test--) {
		int arr[100] = { 0 };
		scanf("%s", str);
		for(i = 0; str[i]; i++) g[0][i] = (str[i]=='Y')? 1 : 0;
		for(n = i, j = 1; j < n; j++) {
			scanf("%s", str);
			for(i = 0; str[i]; i++) g[j][i] = (str[i]=='Y')? 1 : 0;
		}
		best = idx = 0;
		for(k = 0; k < n; k++) {
			for(i = 0; i < n; i++) {
				for(j = 0; j < n; j++) {
					if(i != j) {
						if((g[i][j] == 0) && ((g[i][k] * g[k][j]) == 1)) {
							arr[i]++;
						}
					}
				}
			}
		}
		best = arr[0];
		idx = 0;
		for (int i = 1; i < n; i++) {
			if(arr[i] > best) {
			    best = arr[i];
			    idx = i;
			}
		}
		printf("%d %d\n", idx, best);
	}
	return 0;
}
