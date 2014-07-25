#include <cstdio>
#include <conio.h>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		if(c > a && c > b) printf("NO\n");
		else if(!c) printf("YES\n");
		else if(c == a || c == b) printf("YES\n");
		else if(c % __gcd(a, b)) printf("NO\n");
		else printf("YES\n");
	}
	getch();
	return 0;
}
