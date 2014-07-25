# include <cstdio>
# include <conio.h>
# include <queue>
using namespace std;
int adj[8][8] = {
{   0,1,1,0,0,0,0,0  },
{   1,0,0,0,0,0,0,0  },
{   1,0,0,1,0,0,0,0  },
{   0,0,1,0,1,1,0,0  },
{   0,0,0,1,0,1,1,0  },
{   0,0,0,1,1,0,1,1  },
{   0,0,0,0,1,1,0,1  },
{   0,0,0,0,0,1,1,0  },
	};
int pred[8] , d[8];
char c[8];
void printpath(int s , int i)
{
	if(s == i)printf("%d " , s);
	else if (d[i] == -1)printf("No path from %d to %d" , s , i);
	else {
		printpath(s , pred[i]);
		printf("%d " , i);
	}
}
void BFS(int s)
{
    queue<int> q;
	int i,u;
    for(i=0;i<8;i++) {
		pred[i] = -1;
		d[i] = -1;
		c[i] = 'w';
	}
	c[s] = 'g';
	d[s] = 0;
	q.push(s);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for(i=0;i<8;i++) {
			if(adj[u][i] == 1) {
				if(c[i] == 'w') {
					c[i] = 'g';
					d[i] = d[u] + 1;
					pred[i] = u;
					q.push(i);
				}
			}
		}
		c[u] = 'b';
	}
}
int main()
{
	int s,i;
	scanf("%d" , &s);
	BFS(s);
	for(i=0;i<8;i++){
		printpath(s , i);
		printf("\n");
	}
	getch();
	return 0;
}

