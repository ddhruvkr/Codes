#include <cstdio>

using namespace std;

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


bool p[10000005];
int cost[10000005];
int server[352][352];
bool v[352][352];
char eop[352][352];
int n;
char ch;

void sieve() {
	int i, j;
	p[0] = p[1] = false;
	for(i = 2; i < 10000000; i++) {
		p[i] = true;
	}
	for(i = 2; i*i <= 10000000; i++) {
		if(p[i]) {
			for(j = i*i; j <= 10000000; j += i) {
				p[j] = false;
			}
		}
	}
}

void costprimenos() {
	int x = 0;
	for(int i = 2; i < 10000000; i++) {
		if(p[i] == true) {
			cost[i] = x;
			x++;
		}
	}
}

bool isPrime(int k) {
	if(p[k] == true)return true;
	else return false;
}

bool isEven(int k) {
	if(k % 2 == 0)return true;
	else return false;
}

void dfs(int i, int j) {
    if(v[i][j] == true)return;
	
	else if(eop[i][j] == 'p') {
		return;
	}
	
	else if(eop[i][j] == ch) {
        v[i][j] = true;
		if(i > 1)
			dfs(i-1,j);
		if(i < n)
			dfs(i+1,j);
		if(j > 1)
			dfs(i,j-1);
		if(j < n)
			dfs(i,j+1);
	}
}

int main() {
	int t, j, x, i, uns_pri, uns_odd, uns_even;
	long long int ans;
	//scanf("%d", &t);
	t = read_int();
	sieve();
	costprimenos();
	while(t--) {
		ans = 0;
		//scanf("%d", &n);
		n = read_int();
		for(i = 1; i <= n; i++)
		for(j = 1; j <=n ;j++) {
			//scanf("%d", &server[i][j]);
			server[i][j] = read_int();
			v[i][j] = false;
			if(isPrime(server[i][j]))eop[i][j] = 'p';
			else if(isEven(server[i][j]))eop[i][j] = 'e';
			else eop[i][j] = 'o';
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				if(v[i][j] == false) {
					if(eop[i][j] == 'p') {
						uns_pri = cost[server[i][j]];
						ans += uns_pri;
					}
					else if(eop[i][j] == 'e') {
						ch = 'e';
						uns_even = 0;
						uns_even += (server[i][j]) / 2;
						ans += uns_even;
						dfs(i, j);
					}
					else {
						ch = 'o';
						uns_odd = 1;
						uns_odd += (server[i][j] + 1) / 2;
						ans += uns_odd;
						dfs(i, j);
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
