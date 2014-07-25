#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> f;
	vector <int > a;
	vector <long long int> sum;
	long long int ang = 0, max = 0, max1 = 0;
	int t, n, x, y, i, index;
	cin >> t;
	while(t--){
		ang = 0;
		cin >> n;
		for(i = 0; i < n; i++){
			cin >> x;
			cin >> y;
			f.push_back(x);
			a.push_back(y);
			sum.push_back(f[i]+a[i]);
			ang = ang + a[i];
		}
		max = 0;
		for(i = 0; i < n; i++){
			if(sum[i] > max){
				max = sum[i];
				index = i;
			}
		}
		max1 = 0;
		for(i = 0; i < n; i++){
			if(sum[i] > max1 && i != index){
				max1 = sum[i];
			}
		}
		long long int ans = max + max1 - ang;
		cout << ans << endl;

	}
    return 0;
}
