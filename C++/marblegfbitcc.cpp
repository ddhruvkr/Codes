/*inline int inp( )
{
int n=0;
int ch=getchar_unlocked();
while( ch <48 )ch=getchar_unlocked();
while( ch >47 )
n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
return n;
}*/



#include <cstdio>
#include <iostream>

using namespace std;

long long int fenwick[10000001] = {0};

long long int read(int idx) {
	long long int sum = 0;
	while(idx > 0) {
		sum += fenwick[idx];
		idx -= ((idx) & (-idx));
	}
	return sum;
}

void update(int idx, int m, int n) {
	while(idx <= n) {
		fenwick[idx] += m;
		idx += ((idx) & (-idx));
	}
}

long long int readSingle(int idx) {
	long long int sum = fenwick[idx];
	int z = idx - (idx & (-idx));
	idx--;
	while(idx > z) {
		sum -= fenwick[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

int main() {
	int n, q, i, input, x, y;
	char c;
	scanf("%d%d", &n, &q);
	for(i = 0; i < n; i++) {
        scanf("%d", &input);
		update(i + 1, input, n);
	}
	for(i = 0; i < q; i++) {
		cin >> c;
		scanf("%d %d", &x, &y);
		//gets(c);
		//x = c[2] - '0';
		//y = c[4] - '0';
		if(c == 'S' && x == y)printf("%lld\n", readSingle(x + 1));
		else if(c == 'S')printf("%lld\n", read(y + 1) - read(x));
		else if(c == 'G')update(x + 1, y, n);
		else if(c == 'T')update(x + 1, -y, n);
	}
	return 0;
}
