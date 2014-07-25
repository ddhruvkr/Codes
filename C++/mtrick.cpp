#include <cstdio>
#include <cstring>
#define gc getchar_unlocked

using namespace std;

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

unsigned long long int read_llu() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  unsigned long long int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

unsigned long long int fnc(unsigned long long int x, unsigned long long int y, unsigned long long int z){
	unsigned long long int ans=0, m;
	m = x%z;
	while (y > 0) {
		if (y%2 == 1) {
			ans=(ans%z + m%z)%z;
		}
		m = (m*2)%z;
		y = y/2;
	}
	return ans%z;
}

int main() {
	int t, n, i, j, len, k, low, high;
	unsigned long long int a, b, c;
	char s[1005];
	unsigned long long int l[1005];
	unsigned long long int q, add, mul;
	t = read_int();
	while(t--) {
		n = read_int();
		for(i = 0; i < n; i++)l[i] = read_llu();
		a = read_llu();
		b = read_llu();
		c = read_llu();
		scanf("%s", &s);
		char ch = 'l';
		low = 0;
		add = 0;
		mul = 1;
		high = n-1;
		for(i = 0; i < n; i++) {
			if(s[i] == 'R') {
				if(ch == 'l') {
                    l[high] = fnc(l[high], mul, c);
					l[high] = (l[high]%c + add%c)%c;
					printf("%llu", l[high]);
					ch = 'h';
					high--;
				}
				else {
                    l[low] = fnc(l[low], mul, c);
                    l[low] = (l[low]%c + add%c)%c;
                    printf("%llu", l[low]);
					low++;
					ch = 'l';
				}
			}
			else if(s[i] == 'A') {
				add = (add%c + a%c)%c;
				if(ch == 'h') {
					l[high] = fnc(l[high], mul, c);
					l[high] = (l[high]%c + add%c)%c;
					printf("%llu", l[high]);
					high--;
				}
				else {
                    l[low] = fnc(l[low], mul, c);
                    l[low] = (l[low]%c + add%c)%c;
                    printf("%llu", l[low]);
					low++;
				}
			}
			else {
                mul = fnc(mul, b, c);
                add = fnc(add, b, c);
				if(ch == 'h') {
					l[high] = fnc(l[high], mul, c);
					l[high] = (l[high]%c + add%c)%c;
					printf("%llu", l[high]);
					high--;
				}
				else {
                    l[low] = fnc(l[low], mul, c);
                    l[low] = (l[low]%c + add%c)%c;
                    printf("%llu", l[low]);
					low++;
				}
			}
			if (i != n -1) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
