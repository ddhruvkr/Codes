# include <stdio.h>
# include <conio.h>
# include <string.h>

int c[10001][10001];
char ch[10001][10001];
char x[10000], y[10000];
int m, n;

void lcs() {
	int i, j;
	for(i = 1; i <= m; i++)c[i][0] = 0;
	for(i = 1; i <= n; i++)c[0][i] = 0;
	c[0][0] = 0;
	for(i = 1; i <= m; i++) {
		for(j = 1; j <= n; j++) {
			//printf("h");
			if(x[i - 1] == y[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
				ch[i][j] = 'd';
			}
			else if(c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				ch[i][j] = 'u';
			}
			else {
				c[i][j] = c[i][j - 1];
				ch[i][j] = ' ';
			}
		}
	}
}

void print(int a, int b) {
	if(a == 0 || b == 0)return;
	if(ch[a][b] == 'd') {
		print(a - 1, b - 1);
		printf("%c", x[a - 1]);
	}
	else if(ch[a][b] == 'u') {
		print(a - 1, b);
	}
	else print(a, b - 1);
}

int main()
{
	int i, j;
	scanf("%s%s",x,y);
	m = strlen(x);
	n = strlen(y);
	lcs();
	/*for(i = 0; i < 8; i++) {
		for(j = 0; j < 7; j++) {
			printf("%c ", ch[i][j]);
		}
		printf("\n");
	}*/
	print(m, n);
	printf("\n%d\n",c[m][n]);
	getch();
	return 0;
}
