#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007LL
#define ill int long long
ill gcd(ill a, ill b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}


int main(){
	vector <ill> v;
	
	ill ans, t, n, i, j, ind;
	ill arr[100005];
	ill a[100005];
	cin >> t;
	while(t--){
		v.clear();
		cin >> n;
		for(i = 1; i <= n; i++){
			cin >> arr[i];
			a[i] = 0;
		}
		for(i = 1; i <= n; i++){
			if(a[i] != -999){
				a[i] = -999;
				j = 1;
				ind = arr[i];
				while(ind != i){
					a[ind] = -999;
					j++;
					ind = arr[ind];
				}
				a[i] = j;
				if(j != 1)
				v.push_back(j);
			}
		}
		ans = 1;
		//for(i = 0; i < v.size(); i++)cout << v[i];
		for(i = 0; i < v.size(); i++){
			//if(a[i] != -999)

			for(j = i+1; j < v.size(); j++){
				//if(a[j] != -999)
				v[j] = v[j] / (gcd(v[i], v[j]));
			}
			ans = (ans * v[i])% MOD;
		}
		cout << ans << endl;
		//for(i = 1; i <= n; i++)cout << a[i] << " ";
	}
	return 0;
}
