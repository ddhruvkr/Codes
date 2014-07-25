#include <stdio.h>

#define gc getchar_unlocked

int n;
int a[100001];
/*
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

long long int read_ll() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  long long int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

*/
long long int kadane() {
	int ind = 0, i;
	long long int sum, min;
	min = 0;
	sum = a[0];
	for(i = 1; i < n; i++) {
		if(sum + a[i] < a[i]){
			sum = sum + a[i];
		}
		else sum = a[i];
		if(min > sum)min = sum;
	}
	return min;
}

int main() {
	
	long long int t, i;
	long long int sum;
	//t = read_int();
	scanf("%lld", &t);
	while(t--) {
		sum = 0;
		//n = read_int();
		scanf("%lld", &n);
		sum = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		//a[i] = read_ll();
		long long int ans = kadane();
		printf("%lld\n", sum - 2*ans);
	}
	return 0;
}
