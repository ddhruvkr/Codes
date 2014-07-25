#include <iostream>
using namespace std;

int arr[105][105], ans[105][105];
int n, m;

void solve(int x, int y){
	if((x+1) < n && arr[x+1][y] > arr[x][y]){
		ans[x+1][y] = ans[x][y]+1;
		solve(x+1, y);
	}
	if((y+1) < m && arr[x][y+1] > arr[x][y]){
		ans[x][y+1] = ans[x][y]+1;
		solve(x, y+1);
	}
}



int main()
{
	int max = 1, t, i, j;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(i = 1; i <= n; i++)for(j = 1; j <= m; j++){cin >> arr[i][j]; ans[i][j] = 0;}
		ans[1][1] = 1;
		solve(1,1);
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++)
			cout  << ans[i][j];
			cout << endl;
		}
		/*if(max < ans[i][j])max = ans[i][j];*/
		cout << max << endl;
	}
    return 0;
}
