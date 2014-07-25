#include <cstdio>
#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;

int a[100][100];

int vi[100];
int f[100];

int t = 0;
int n;

void dfs(int i) {
	t++;
	vi[i] = 1;
	for(int j = 0; j < n; j++) {
		if (a[i][j] == 1 && vi[j] == 0) dfs(j);
	}
	t++;

	f[i] = t;
	return;
}

void dfsont(int i) {
	cout << i << "-> ";
	vi[i] = 1;
	for(int j = 0; j < n; j++) {
		if (a[i][j] == 1 && vi[j] == 0) dfsont(j);
	}
	return;
}

int main()
{
	int m, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf ("%d", &a[i][j]);
	}

	for (int i = 0; i < n; i++) {
		if (vi[i] == 0)
		dfs(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		vi[i] = 0;
	}
	while (1) {
		int j;
		for (j = 0; j < n; j++) if (vi[j] == 0) break;
		if (j == n) break;
		int x, i;
		for (x = 0; x < n; x++) if (vi[x] == 0) {
				i = x;
				break;
		}
		for (x; x < n; x++) {
			if (f[x] > f[i] && vi[x] == 0) i = x;
		}
			cout << "Component = ";
			dfsont(i);
			cout << "NULL" << endl;
	}
	getch();

	return 0;
}
