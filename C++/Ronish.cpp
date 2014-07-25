#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
vector<int> arr[10000000000];
int a[20];
int m,n, u = 0, no = 0;
queue <int> q;
stack <int> s;

int insert(int i) {
	int y = 0;
	for (int x = 0; x <= n - 1; x++) {
		if ((arr[i] * a[x]) < m) {
			arr[(i * n) + y] = arr[i] * a[x];
			q.push((i * n) + y);
		}
		if ((arr[i] * a[x]) == m) {
			u = 1;
			arr[((i * n) + y)] = m;
		    return ((i * n) + y);
		}
		y++;
	}
	return -1;
}

void heap() {
	int r, k;
	while (!q.empty()) {
		k = q.front();
		q.pop();
		r = insert (k);
		if (u == 1) break;
	}
	if (u == 1) {
		while (r != 0) {
			s.push(arr[r]);
			r = r / n;
			no++;
		}
		cout << no - 1 << endl;
		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
	else if (u == 0)
	cout << "-1" << endl;
}
int main() {
	int k,i;
	for(k=0;k<100;k++) {
		no = 0, u = 0;
		scanf("%d%d",&m,&n);
		
		for(i=0;i<n;i++)
			cin >> a[i];
		arr[1] = 1;
		q.push(1);
		heap();
	}
	return 0;
}
