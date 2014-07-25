#include <stdio.h>

/*#define gc getchar_unlocked

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
}*/


/*long long int power(long long int x, long long int n) {
	long long int res = 1;
    while(n > 0) {
        if (n & 1) {
            res = res * x;
		}
        x = x * x;
        n >>= 1;
	}
	return res;
}
*/
int main() {
	int t, i;
	long long int l, d, s, c, ans;
	//t = read_int();
	scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld%lld", &l, &d, &s, &c);
		//l = read_ll();
		//d = read_ll();
		//s = read_ll();
		//c = read_ll();
		if(d == 1)ans = s;
		else if(d == 2)ans = s + c*s;
		else  {
            ans = s + c*s;
			for(i = 3; i <= d; i++) {
				ans = ans + c*ans;
				if(ans >= l) {
					break;
				}
			}
		}
		if(ans >= l)printf("ALIVE AND KICKING\n");
		else printf("DEAD AND ROTTING\n");
	}
	return 0;
}
