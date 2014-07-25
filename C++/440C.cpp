#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, k, p, i, even = 0, odd = 0;
	vector <int>arr;
	cin >> n >> k >> p;
	for(i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] % 2 == 0)even++;
		else odd++;
	}
	if(odd < k-p){
		cout << "NO" << endl;
		return 0;
	}
	if(even + (odd - k + p)/2 < p){
        cout << "NO" << endl;
		return 0;
	}
	cout << "YES";
	
}

