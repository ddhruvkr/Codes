#include <iostream>
#include <algorithm>

using namespace std;

struct frog{
	int id, x;
}frogs[100005];

bool cmp(const frog &a, const frog &b)
{
	return a.x < b.x;
}

int main(){
	int arr[100005];
	int j, n, k, p, x, y, i;
	cin >> n >> k >> p;
	for(i = 0; i < n; i++){
		cin >> frogs[i].x;
		frogs[i].id = i;
	}
	sort(frogs, frogs+n, cmp);
	/*for(i = 1; i <= n; i++){
		cout << frogs[i].id << " " << frogs[i].x;
		cout << endl;
	}*/

	arr[frogs[0].id] = frogs[0].id;
	for(i = 1; i < n; i++){
		arr[frogs[i].id] = frogs[i].id;
		if(frogs[i].x - frogs[i-1].x <= k)
		arr[frogs[i].id] = arr[frogs[i-1].id];
		
	}
	
	/*for(i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	/*for(i = 1; i <= n; i++){
		arr[frogs[i].id] = arr[arr[frogs[i].id]];
	}*/
	/*for(i = 1; i <= n; i++){
		cout << arr[i] << endl;
	}*/
	for(i = 0; i < p; i++){
		cin >> x >> y;
		if(arr[x-1] == arr[y-1])cout  << "Yes" << endl;
		else cout  << "No" << endl;
	}
	return 0;
}
