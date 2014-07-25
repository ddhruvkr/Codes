#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

int x[10];
int count = 0;

void print(int n) {
	int i, j;
	char arr[n+1][n+1];
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			arr[i][j] = '.';
		}
	}
    //char arr[5][5] = {{'.','.','.','.','.'}, {'.','.','.','.','.'}, {'.','.','.','.','.'}, {'.','.','.','.','.'}, {'.','.','.','.','.'}};
	for(i = 1; i <= n; i++) {
		arr[i][x[i]] = 'Q';
	}
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool check(int i, int j) {
	int d;
	for(d = 1; d < i; d++) {
		if(x[d] == j)return false;
	}
	for(d = 1; d < i; d++) {
		if(abs(x[d] - j) == abs(d - i))return false;
	}
	return true;
}

bool place(int i, int n) {
	int j;
	for(j = 1; j <= n; j++) {
		x[i] = j;
		if(check(i, j)) {
			if(i == n) {
				print(n);
				count++;
				return true;
			}
			else
			place(i+1, n);
		}
	}
	//return false;
}

int main() {
	int i, n;
	scanf("%d", &n);
	place(1, n);
	printf("%d\n",count );
	getch();
	return 0;
}
