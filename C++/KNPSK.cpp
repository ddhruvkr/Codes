#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;

/*bool cmp(int a, int b){
	return b>a;
}*/
long long int one[100005], two[100005];
	long long int dp[200005];
int main(){
	long long int i, n, w, c, j = 0, k = 0, m = 0, a, b, oj, ok;
	cin >> n;
	
	for(i = 0; i < n; i++){
		cin >> w >> c;
		m = m + w;
		if(w == 1)one[j++] = c;
		else two[k++] = c;
	}
	sort(one, one+j);
	sort(two, two+k);
	j--;k--;
	oj = j;
	ok = k;
	if(m > 0)
	dp[1] = one[oj];
	oj--;
	if(m > 1){
		if(j > 0)
		a = one[j] + one[j-1];
		else a = -5;
		if(k >= 0)b = two[k];
		else b = -5;
		if(a > b){
			j = j-2;
			dp[2] = a;
		}
		else {
			j--;
			k--;
			dp[2] = b;
		}
	}
	for(i = 3; i <= m; i++){
		if(i % 2 == 0){
			if(j >= 1){
				a = dp[i-2] + one[j] + one[j-1];
			}
			if(k >= 0){
				b = dp[i-2] + two[k];
			}
			if(oj >= 0){
				c = dp[i-1] + one[oj];
			}
			if(a >= b && a >= c){
				dp[i] = a;
				j = j-2;
			}
			else if(b >= a && b >= c){
				dp[i] = b;
				k--;
			}
			else if(c >= a && c >= b){
				dp[i] = c;
				j = oj-1;
			}
		}
		else{
			if(oj >= 1){
				a = dp[i-2] + one[oj] + one[oj-1];
			}
			if(ok >= 0){
				b = dp[i-2] + two[ok];
			}
			if(j >= 0){
				c = dp[i-1] + one[j];
			}
			if(a >= b && a >= c){
				dp[i] = a;
				oj = oj-2;
			}
			else if(b >= a && b >= c){
				dp[i] = b;
				ok--;
			}
			else if(c >= a && c >= b){
				dp[i] = c;
				oj = j-1;
			}
		}
	}
	for(i = 1; i <= m; i++)cout << dp[i] << " ";
	cout << endl;
	getch();
	return 0;
}
