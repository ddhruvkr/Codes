#include <stdio.h>

#define gc getchar_unlocked

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int a[500001], dp[1000001];
int n, k;

int main() {
	int i, cnt, min = 99999999, mini, d;
	n = read_int();
	k = read_int();
	//scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++) {
		//scanf("%d", &a[i]);
		a[i] = read_int();
	}
	for(i = 0; i < 1000001; i++)dp[i] = min;
	cnt = 0;
	if(n % 2 == 0) {
		for(i = 0; i < n/2; i++) {
			cnt++;
			if(dp[a[i]] > cnt)dp[a[i]] = cnt;
		}
		for(i = n/2; i < n; i++) {
			if(dp[a[i]] > cnt)dp[a[i]] = cnt;
			cnt--;

		}
	}
	else {
		for(i = 0; i <= n/2; i++) {
			cnt++;
            if(dp[a[i]] > cnt)dp[a[i]] = cnt;
		}
		for(i = n/2 + 1; i < n; i++) {
			cnt--;
            if(dp[a[i]] > cnt)dp[a[i]] = cnt;
		}
	}
	//for(i = 0; i < 10; i++)printf("%d ", dp[i]);
	//printf("\n");
	for(i = 0; i < n; i++) {
		d = k - a[i];
		if(d > 0 && d != a[i]) {
			if(dp[a[i]] != 99999999 && dp[d] != 99999999) {
                mini = (dp[a[i]] < dp[d] ? dp[d] : dp[a[i]]);
                if(min > mini)min = mini;
			}
		}
	}
	if(min != 99999999)
	min = -1;
	printf("%d\n", min);
	/*for(i = 0; i < n; i++)printf("%d ", y[i]);
	printf("\n");
	quicksort(0, n - 1);
	for(i = 0; i < n; i++)printf("%d ", x[i]);
	printf("\n");
	for(i = 0; i < n; i++)printf("%d ", y[i]);
	printf("\n");*/
	return 0;
}
