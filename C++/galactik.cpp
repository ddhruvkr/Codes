//By use of disjoint set...could also be done with dfs..find different connected graphs with help of dfs...find the min connection then apply formula..
# include <cstdio>
# include <conio.h>
# include <algorithm>

using namespace std;

int p[100010], r[100010];
int cost[100010];
int c[100010], neg[100010];


void init(int n) {
	for(int i = 1; i <= n; i++) {
		p[i] = i;
		r[i] = 0;
	}
}

int find(int u) {//finds the root so to check if elements in same set or not
	if(p[u] == u)return u;
	else return p[u] = find(p[u]);
}

void join(int a, int b) {
	int i = find(a);
	int j = find(b);
	if(i == j)return;
	if(r[i] < r[j])p[i] = b;
	else {
		p[i] = j;
		if(r[i] == r[j])r[i]++;
	}
}

int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    init(n);
    for(int i = 0; i < m; i++) {
        int s, e;
        scanf("%d %d",&s,&e);
        join(s,e);
    }
	for(int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	}
	for(int i = 1; i <= n; i++) {
		c[i] == 0;
		neg[i] = 10001;
	}
	for(int i = 1; i <= n ; i++)printf("%d ", neg[i]);
	printf("\n");
	for(int i = 1; i <= n; i++) {
		int p = find(i);
		c[p]++;
		if(cost[i] >= 0) {
			neg[p] = min(cost[i], neg[p]);
		}
	}
	for(int i = 1; i <= n ; i++)printf("%d ", neg[i]);
	printf("\n");
	int sub = 0, sum = 0, f = 0, l = 10001;
	for(int i = 1; i <= n; i++) {
		if(c[i] > 0){
			sub++;
			sum += neg[i];
			if(neg[i] == 10001) f = 1;
            l = min(l, neg[i]);
		}
	}
	printf("%d %d  %d %d\n", sub, l, sum, f);
	if(sub == 1)printf("0\n");
	else {
		if(f)printf("-1\n");
		else printf("%d\n", (sub - 1)*l + sum - l);
	}
	getch();
	return 0;
}
