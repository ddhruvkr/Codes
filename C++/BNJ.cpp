#include <iostream>
#include <cstdio>

using namespace std;
int t[] = {1, 3, 2, 6, 4, 5};

int main()
{
	while (1) {
	string a;
	long long int i = 0;
	int l = 0, s = 0;
	int c[10] = {0};
	int g[10] = {0};
	int j = 0, r = 0;
	cin >> a;
	if (!cin.eof()) {
	string :: iterator p = a.begin();
	while (p != a.end()) {
		c[*p - '0']++;
		i = i + *p - '0';
		l++;
		p++;
	}
	l--;
	p = a.end();
	p--;
	if (c[7] > 0) {
	while (p != a.begin()) {
		s = s + ((*p) - '0') * (t[j % 6]);
	//	cout << s << " ";
		j++;
		p--;
	}
	s = s + ((*p) - '0') * (t[j % 6]);
    if (s % 7 == 0) g[7] = 1;
	}
	g[1] = 1;
	if ((a[l] - '0') % 2 == 0) g[2] = 1;
	if (i % 3 == 0) g[3] = 1;
	if ((a[l] - '0') == 5 || a[l] - '0' == 0) g[5] = 1;
	if (g[3] == 1 && g[2] == 1) g[6] = 1;
	if (i % 9 == 0) g[9] = 1;

 	if (l > 1) {
	 	if (((a[l] - '0') + 10 * (a[l - 1] - '0')) % 4 == 0)
	 	g[4] = 1;
 	}
 	else if ((a[l] - '0') % 4 == 0)
	g[4] = 1;

	if (l > 2) {
		if (((a[l] - '0') + 10 * (a[l - 1] - '0') + 100 * (a[l - 2] - '0')) % 8 == 0)
		g[8] = 1;
	}
	else if (l == 2) {
		if (((a[l] - '0') + 10 * (a[l - 1] - '0')) % 8 == 0)
	 	g[8] = 1;
	}
	else if ((a[l] - '0') % 8 == 0)
	g[8] = 1;
 	for (int x = 1; x < 10; x++) {
	 	r = r + c[x] * g[x];
	 //	cout << x << " " << c[x] << " " << g[x] << endl;
	 }
	cout << r << endl;
	}
	else break;
	}
	return 0;
}

