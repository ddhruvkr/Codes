#include <stdio.h>

int main() {
	int t, n, m, mask, ans, sum, i;
	int a[100];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		for(mask = 0; mask < 1<<n; mask++) {
			sum = 0;
			for(i = 0; i < n; i++) {
				if(mask & 1<<i) {
					sum = sum + a[i];
					if(sum > m)i = n;
				}
			}
			if(sum == m) {
				ans = 1;
				break;
			}
		}
		if(ans == 1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
