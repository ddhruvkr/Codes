#include <stdio.h>
#define SL(x, n) ((x)<<(n))
int main() {
	int test, cs = 1, k, i;
	long long int l, p, c, x;
	scanf("%d", &test);
	while(test--) {
		scanf("%lld%lld%lld", &l, &p, &c);
		k = i = 0; x = l;
		while(x < p) {
			x *= c;
			k++;
		}
		printf("%d\n",k);
		while(SL(1, i) < k) i++;
		printf("Case #%d: %d\n", cs++, i);
	}
	return 0;
}
