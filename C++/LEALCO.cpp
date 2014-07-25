#include <iostream>
#include <vector>
using namespace std;

bool isBad(vector<int> r, int k, int m) {
	int n = r.size();
	for (int i = 0; i <= n - k; ++i) {
		int maxR = 0;
		for (int j = i; j < k + i; ++j) {
			if(maxR < r[j])maxR = r[j];
		}
		int count = 0;
		for (int j = i; j < k + i; ++j) {
			if(r[j] == maxR) {
				++count;
			}
		}
		if (count >= m) {
			return true;
		}
	}
	return false;
}

int popcount(int x) {
	int res = 0;
	while (x > 0) {
		x -= x & -x;
		++res;
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		int n, k, m;
		cin >> n >> k >> m;
		vector<int> r(n);
		for (int i = 0; i < n; ++i) {
			cin >> r[i];
		}
		int res = n + 1;
		for (int mask = 0; mask < (1<<n); ++mask) {
			int size = popcount(mask);
			if (res <= size) {
				continue;
			}
			vector<int> nr(n);
			for (int i = 0; i < n; ++i) {
				if (mask & 1<<i) {
					nr[i] = r[i] + 1;
				} else {
					nr[i] = r[i];
				}
			}
			if (!isBad(nr, k, m)) {
				res = size;
			}
		}
		if (res == n + 1) {
			res = -1;
		}
		cout << res << endl;
	}
	return 0;
}
