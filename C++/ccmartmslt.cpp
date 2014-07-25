#include <stdio.h>
#define gc getchar_unlocked
#define pc putchar_unlocked

int count[1000010];

/*long long int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}*/

int main(){
	long long int t, n, a, b, c, d, i, value, j;
	long long int t1, t2;
	scanf("%d", &t);
	while(t--){
		//n = read_int();
		//a = read_int();
		//b = read_int();
		//c = read_int();
		//d = read_int();
		scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
        for (i = 0; i <= 1000000; i++) {
              count[i] = 0;
        }
        count[d] = 1;
		for(i = 1; i < n; i++){
			value = (a*d*d + b*d + c) % 1000000;
			count[value]++;
			d = value;
		}
		t1 = 0;
		t2 = 0;
		j = 0;
		for(i = 1000000; i >= 0;){
			if(j % 2 == 0 && count[i]){
				t1 += i;
				count[i]--;
				j++;
			}
			else if(count[i]){
				t2 += i;
				count[i]--;
				j++;
			}
			if(count[i] == 0)i--;
			if(j == n)break;
		}
		if(t1 > t2)printf("%lld\n", t1-t2);
		else printf("%lld\n", t2-t1);
	}
	return 0;
}
