#include <stdio.h>

int main() {
	int t, n, i, maxv, v;
	int a[100001];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		maxv = 0;
		for(i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			v = a[i] + i - 1;
			if(v > maxv)maxv = v;
		}
		printf("%d\n", maxv);
	}
	return 0;
}
