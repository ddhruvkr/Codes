#include <stdio.h>
#include <string.h>
#include <conio.h>

int f[4000001];
char s[4000001];

void failure() {
	int i, j;
	f[0] = f[1] = 0;
	int m = strlen(s);
	for(i = 2; i <= m; i++) {
		j = f[i - 1];
		while(1) {
			if(s[j] == s[i - 1]) {
				f[i] = j + 1;
				break;
			}
			if(j == 0) {
				f[i] = 0;
				break;
			}
			j = f[j];
		}
	}
	for(i = 1; i <= m; i++)
	printf("%d ", f[i]);
	printf("\n");
}

int main() {
	while(1) {
		scanf("%s", s);
		if(strcmp(s, "End") == 0) break;
		failure();
	}
	return 0;
}
