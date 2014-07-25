# include <stdio.h>
void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permute(char a[], int i, int n) {
	int j;
	if(i == n)printf("%s\n" , a);
	else {
		for(j = i; j <= n; j++) {
			swap(a + i, a + j);
			permute(a, i+1, n);
			swap(a + i, a + j);//backtracking
		}
	}
}
int main() {
	char s[] = "abcdef";
	permute(s, 0, 5);
	getchar();
	return 0;
}
