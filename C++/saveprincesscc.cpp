#include <stdio.h>
double a[101][10000];
int main() {
	double p[101];
	int A[101];
	double add, d;
	int t, sum, sum1, i, j, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		sum = 0;
		for(i = 1; i <= n; i++) {
			scanf("%d" , &A[i]);
			sum = sum + A[i];
		}
		for(i = 1; i <= n; i++) {
			scanf("%lf" , &d);
			p[i] = d / 100;
		}
		for(i = 1; i < n + 1; i++)a[0][i] = 0.0;
		a[0][0] = 1.0;
		for(i = 1; i <= n; i++) {
			a[i][0] = 1.0 - p[i];
			if(i - 1 > 0)a[i][0] = a[i][0] * a[i-1][0];
			for(j = 1; j <= sum; j++) {
				if(j - A[i] >= 0)
				a[i][j] = (a[i - 1][j - A[i]] * p[i]) + (a[i - 1][j] * (1.0 - p[i]));
				else a[i][j] = (a[i - 1][j] * (1.0 - p[i]));
			}
		}
		add = 0;
		if(sum % 2 == 0)sum1 = sum / 2;
		else sum1 = (sum + 1)/2;
		for(j = sum1; j <= sum; j++) {
			add = add + a[n][j];
		}
		printf("%.7lf\n", add);
	}
	return 0;
	
}
