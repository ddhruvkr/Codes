# include <cstdio>
# include <cstring>
using namespace std;
int main() {
	int t, a, b, l, sum, i;
	char s[50002];
	scanf("%d" , &t);
	while(t--) {
		scanf("%s", s);
		l = strlen(s);
		sum = 0;
		a = 0;
		b = 0;
		for(i = 0; i < l; i++) {
            sum = ((sum * 10) + (s[i] - '0')) % 4;
		}
		if(sum == 0)a++;
		sum = 0;
		for(i = 0; i < l; i++) {
            sum = ((sum * 10) + (s[i] - '0')) % 7;
		}
		if(sum == 0){ a++; b++; }
		sum = 0;
		for(i = 0; i < l; i++) {
            sum = ((sum * 10) + (s[i] - '0')) % 9;
		}
		if(sum == 0)a++;
		sum = 0;
		for(i = 0; i < l; i++) {
            sum = ((sum * 10) + (s[i] - '0')) % 3;
		}
		if(sum == 0)b++;
		sum = 0;
		for(i = 0; i < l; i++) {
            sum = ((sum * 10) + (s[i] - '0')) % 25;
		}
		if(sum == 0)b++;
		if(a == 3)printf("Yes ");
		else printf("No ");
		if(b == 3)printf("Yes\n");
		else printf("No\n");
	}
}
