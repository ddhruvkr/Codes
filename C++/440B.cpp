#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	long long int d, n, i, k;
	long long int s = 0;
	long long int arr[50001];
	cin >> n;

	for(i = 0; i < n; i++){
		cin >> arr[i];
		s = s+ arr[i];
	}
	k = s/n;
	s = 0;
	for(i = 1; i < n; i++){
		d = k - arr[i-1];
		arr[i] -= d;
		if(d > 0)
		s = s + d;
		else s = s-d;
	}
	cout << s << endl;
	getch();
	return 0;
}
