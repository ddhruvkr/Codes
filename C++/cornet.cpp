# include <cstdio>
# include <cmath>

using namespace std;

int p[20005], d[20005];
//int sum = 0;
void init(int n) {
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		d[i] = 0;
	}
}

int find(int a) {
	if(a == p[a])return a;
	else {
		int i = p[a];
		p[a] = find(p[a]);
		d[a] = d[a] + d[i];
		return p[a];
	}
}

void merge(int a, int b) {
	p[a] = b;
	d[a] = (int)(fabs(a-b)) % 1000;
}

int main() {
	int t, x, y, n;
	char c;
	scanf("%d", &t);
	while(t--) {
		//sum = 0;
		scanf("%d", &n);
		init(n);
		while(1) {
   		//sum = 0;
			//gets(c);
			 scanf( "%*c%c", &c );
			if(c == 'O')break;
			else if(c == 'E') {
    		//sum = 0;
				scanf("%d", &x);
    			//x = c[2] - '0';
				p[x] = find(x);
				printf("%d\n", d[x]);
			}
			else if(c == 'I') {
				//x = c[2] - '0';
				//y = c[4] - '0';
				scanf("%d%d", &x, &y);
                if(find(x) != find(y)) {
                    merge(x,y);
                }
            }
		}
	}
	return 0;
}
