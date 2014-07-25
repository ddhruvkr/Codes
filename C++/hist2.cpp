#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, i, max, cnt, sum,j;
	int a[20];
	scanf("%d", &n);
	while(n != 0) {
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		max = 0;
		sum = 2*n + a[0] + a[n-1];
		for(i = 0, j = n-1; i <= j; i++, j--) {
				sum += a[j] - a[i];
		}
		printf("%d %d\n", sum, cnt);
		scanf("%d", &n);
	}
	return 0;
}
