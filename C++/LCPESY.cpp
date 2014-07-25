#include <stdio.h>
#include <string.h>

int main()
{
	int t, i, ans;
	scanf("%d", &t);
	while (t--) {
	char a[10001], b[10001];
	scanf("%s%s", &a, &b);
		int len1[128];
		int len2[128];
		for (i = 0; i < 128; i++) len1[i] = len2[i] = 0;
		for (i = 0; i < strlen(a); i++) {
			len1[a[i]]++;
		}
		for (i = 0; i < strlen(b); i++) {
			len2[b[i]]++;
		}
		ans = 0;
		for (i = 0; i < 128; i++) {
			ans = ans + (len1[i] < len2[i] ? len1[i] : len2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
