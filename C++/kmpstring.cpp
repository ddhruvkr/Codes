#include <stdio.h>
#include <string.h>
#include <conio.h>

char text[] = "abracadabra";
char pattern[] = "ababbacdbacdbacd";
int m = strlen(pattern);
int n = strlen(text);
int f[100];

void failure() {
	int i, j;
	f[0] = f[1] = 0;
	for(i = 2; i <= m; i++) {
		j = f[i - 1];
		while(1) {
			if(pattern[j] == pattern[i - 1]) {
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
	for(i = 0; i <= m; i++)
	printf("%d ", f[i]);
	printf("\n");
}

void kmp() {
	failure();
	int i = 0;
	int j = 0;
	while(1) {
		if(j == n)break;
		else if(text[j] == pattern[i]) {
			i++;
			j++;
			if(i == m) {
				printf("The match starts at %d position\n", j - m + 1);
			}
		}
		else if(i > 0)i = f[i];
		else j++;
	}
}
int main() {
	kmp();
	getch();
	return 0;
}
