#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n;
	stack<int> s;
	cin >> n;
	int a[n], c[n], k = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		int t = 0;
		while (a[i] == a[i + 1]) {
			i++;
			t = 1;
		}
		c[k++] = a[i];
		if (t == 1) s.push(a[i]);
		if (i == n - 2 && t == 0) c[k++] = a[i + 1];
	}
	if (!s.empty()) {
		int t = s.top();
		s.pop();
		if (t != c[k - 1]) c[k++] = t;
		while (!s.empty()) {
			c[k++] = s.top();
				s.pop();
		}
	}
	cout << k << endl;
	for (int i = 0; i < k; i++) cout << c[i] << " ";
	cout << endl;
	return 0;
}
