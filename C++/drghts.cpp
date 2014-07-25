#include <iostream>
#include <vector>

#define SIZE 50001

//a[x] no of bache which are 1
//dp[x] no of bache which return 1 isko milake...return 1 vo karte hai which have atleast one win 1
using namespace std;


vector<int> v[SIZE];
int w[SIZE], vi[SIZE], qn = 0, dp[SIZE], a[SIZE];
long long int f[SIZE], tr[SIZE];
// f = number of open wimdow nodes

int dfs(int i) {
	vi[i] = 1;
	int n;
	if (w[i] == 1) n = 1;
	else n = 0;
	for (int x = 0; x < v[i].size(); x++) {
		if (vi[v[i][x]] == 0) {
			n = n + dfs(v[i][x]);
		}
	}
	a[i] = n;
	return n;
}

int dfs3(int i) {
	vi[i] = 1;
	int n = 0;
	for (int x = 0; x < v[i].size(); x++) {
		if (vi[v[i][x]] == 0) {
			n = n + dfs3(v[i][x]);
		}
	}
	if (n > 0) dp[i] = ++n;
	else if (n == 0 && w[i] == 1) dp[i] = ++n;
	else dp[i] = n;
	return n;
}


int dfs1(int i) {

	vi[i] = 1;

	
	int s = 0;
    int temp = 0;
	for (int x = 0; x < v[i].size(); x++) {
		if (vi[v[i][x]] == 0) {
			if(a[v[i][x]] > 0)s++;
			//s is no nodes with no of bache which are win = 1
		}
	}
	if (s == 0)return 0;
	if (w[i] == 1 && s == 1) {
		for (int x = 0; x < v[i].size(); x++) {
			if (vi[v[i][x]] == 0) {
				if (a[v[i][x]] > 0) temp = dp[v[i][x]] + 1;
			}
		}
	} else if (s == 1 && w[i] == 0) {
		for (int x = 0; x < v[i].size(); x++) {
			if (vi[v[i][x]] == 0) {
				if (a[v[i][x]] > 0) temp = dfs1(v[i][x]);
			}
		}
	} else if (s > 1) {
		for (int x = 0; x < v[i].size(); x++) {
			if (vi[v[i][x]] == 0){
				if (a[v[i][x]] > 0) temp = temp + dp[v[i][x]];
			}
		}
		temp = temp + 1;
	}
	return temp;
}

int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		vi[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
        v[x].push_back(y);
		v[y].push_back(x);
	}

	int fi = 1, nf, q2 = 0;
	long long q1 = 0;
	for (int i = 1; i <= n; i++) {
		if (vi[i] == 0) {
			tr[fi] = i;
			  f[fi++] = dfs(i);
		}
	}

	nf = fi - 1;

	for (int i = 1; i <= nf; i++) {
		q1 = q1 + (f[i] * (f[i] - 1)) / 2;
	}

	for (int i = 1; i <= n; i++) vi[i] = 0;
	fi = 1;

	for (int i = 1; i <= nf; i++) {
		if (f[i] >= 2) {
			dfs3(tr[i]);
		}
	}

	for (int i = 1; i <= n; i++) vi[i] = 0;
	q2 = 0;
	for (int i = 1; i <= nf; i++) {
			if (f[fi] > 1) {
				q2 = q2 + dfs1(tr[i]);
			}
		}

	cout << q1 << " " << q2 << endl;

	return 0;
}
