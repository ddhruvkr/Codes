# include <cstdio>
# include <conio.h>
using namespace std;
int adj[6][6] = {
{   0,1,1,0,0,0  },
{   0,0,1,0,0,0  },
{   0,0,0,1,0,0  },
{   0,1,0,0,0,0  },
{   0,0,0,1,0,1  },
{   0,0,0,0,0,1  },
	};
int pred[6] , d[6];
char c[6];
int time;

void DFSvisit(int u)
{
	int i;
	c[u] = 'g';
	printf("%d " , u);
	for(i=0;i<6;i++) {
		if(adj[u][i] == 1) {
			if(c[i] == 'w') {
				pred[i] = u;
				DFSvisit(i);
			}
		}
	}
	c[u] = 'b';
}

void DFS()
{
	int i;
	for(i=0;i<6;i++) {
		c[i] = 'w';
		pred[i] = -1;
	}
	for(i=0;i<6;i++) {
		if(c[i] == 'w'){
			DFSvisit(i);
		}
	}
}

int main()
{
	int s,i;
	DFS();
	getch();
	return 0;
}
