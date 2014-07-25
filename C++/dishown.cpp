#include <cstdio>
#include <vector>

using namespace std;
#define S(x) scanf("%d", &x)
int m[10002], v[10002];

int findRoot(int x){
	if(v[x] != x)v[x] = findRoot(v[x]);
	return v[x];
}

int main(){
	int t, x, y, z, i, q, n, Z, Y;
	//int max[10002], v[10002];
	//vector <int> v[10002];
	S(t);
	while(t--){
		S(n);
		//for(i = 0; i < n; i++)v[i].clear();
		for(i = 0; i < n; i++){
			S(x);
			v[i] = i;
			m[i] = x;
			//chefwtdish[i] = i;
		}
		S(q);
		while(q--){
			S(x);
			if(x == 1){
				S(y);
				printf("%d\n", findRoot(y-1)+1);
				//cout << findRoot(y-1)+1 << endl;
			}
			else if(x == 0){
				S(y);
				S(z);
				y--;
				z--;
				Y = findRoot(y);
				Z = findRoot(z);
				if(Y == Z){
					printf("Invalid query!\n");
					//cout << "Invalid query!" << endl;
				}
				else{
					//if(max[chefwtdish[y]] != -999 && max[chefwtdish[z]] != -999)
					//{
					if(m[Y] - m[Z] > 0){
						v[Z] = Y;
							//max[z] = -999;
					}
					if(m[Y] - m[Z] < 0){
						v[Y] = Z;
							//max[y] = -999;
					}
				}
			}
		}
	}
	return 0;
}
