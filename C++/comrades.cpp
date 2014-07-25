#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[100005];
int ts;
int arr[100005][2];
int ht[100005];

void dfs(int v, int h)
{
	ht[v] = h;
	arr[v][0] = ts;
	ts++;
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        dfs(*i, h+1);
    arr[v][1] = ts;
	ts++;
    return;

}



int main()
{


	int i, x, y, n, q, root, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		i=1;
        while(i<=n)
        {
            adj[i].clear();
            arr[i][0]=0;
            arr[i][1]=0;
            i++;
        }

		for(i = 1; i <= n; i++){
			scanf("%d", &x);
			if(x == 0)root = i;
			else adj[x].push_back(i);
		}
        ts = 0;
		dfs(root, 0);
		/*for(i = 1; i < 6; i++){
			cout << ht[i]/* << " " << arr[i][1] << "\n";
		}*/
		scanf("%d", &q);
		for(i = 0; i < q; i++){
			scanf("%d", &x);
			scanf("%d", &y);
			if(arr[x][1] < arr[y][1] && arr[x][0] > arr[y][0])
			cout << ht[x]-ht[y]-1 << endl;
			else cout << "-1" << endl;
		}
	}
    return 0;
}
