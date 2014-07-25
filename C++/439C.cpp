#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int main(){
	int n, k, p, i, even = 0, odd = 0, c, j;
	
	vector<int> a[2];
	cin >> n >> k >> p;
	vector <vector<int> > arr(k);
	for(i = 0; i < n; i++){
		cin >> c;
		if(c % 2 == 0){
			even++;
			a[0].push_back(c);
			//cout << "d";
		}
		else{
			 odd++;
			 a[1].push_back(c);
			 //cout << "s";
		}
	}
	if(odd < k-p){
		cout << "NO" << endl;
		return 0;
	}
	if((odd-(k-p))%2 != 0){
        cout << "NO" << endl;
		return 0;
	}
	if(even + (odd - k + p)/2 < p){
        cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	for(i = 0; i < k-p; i++){
		arr[i].push_back(a[1].back());
		a[1].pop_back();
	}
	for(i = k-p; i < k; i++){
		if(!a[0].empty()){
			arr[i].push_back(a[0].back());
			a[0].pop_back();
		}
		else{
			for(j = 0; j < 2; j++){
	            arr[i].push_back(a[1].back());
				a[1].pop_back();
			}
		}
	}
	
	for(i = 0; i < 2; i++){
		int s = a[i].size();
		for(j = 0; j < s; j++){
			arr[0].push_back(a[i][j]);
		}
	}
	for(i = 0; i < k; i++){
		cout << arr[i].size() << " ";
		int s = arr[i].size();
		for(j = 0; j < s; j++){
			cout << arr[i].back() << " ";
			arr[i].pop_back();
		}
		cout << endl;
	}
	
	
	/*for(i = 0; i < odd-k+p; i++){
		a[0].push_back(a[1].back());
		a[1].pop_back();
	}
	for(i = 0; i < k - p- 1; i++){
		cout << "1" << " " << a[1].back() << endl;
		a[1].pop_back();
	}
	cout << a[1].size() << " ";
	for(i = 0; i < a[1].size(); i++){
		cout << a[1].back() << " ";
		a[1].pop_back();
	}*/
	getch();
	return 0;
	
}

