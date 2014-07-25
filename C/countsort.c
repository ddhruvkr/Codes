#include <stdio.h>

int main() {
	int cnt[11], out[11];
	int i;
    int arr[7] = {1, 4, 1, 2, 7, 5, 2};
	for(i = 0; i < 11; i++)cnt[i] = 0;
	for(i = 0; i < 7; i++) {
		cnt[arr[i]]++;
	}
	for(i = 1; i < 11; i++) {
		cnt[i] += cnt[i - 1];
	}
	for(i = 0; i < 7; i++) {
		out[cnt[arr[i]] - 1] = arr[i];
		cnt[arr[i]]--;
	}
	for(i = 0; i < 7; i++) {
		printf("%d ", out[i]);
	}
	printf("\n");
	getch();
	return 0;
}
