# include <cstdio>
using namespace std;
char c[10001];
int a[100001],b[100001];
bool adj[10001][10001];
int n;
void DFSvisit(int u,int k)
{
	int i;
	c[u] = 'g';
	//printf("%d " , u);
	for(i=1;i<=n;i++) {
		if(i!=k && adj[u][i] == true) {
			if(c[i] == 'w') {
				DFSvisit(i,k);
			}
		}
	}
	c[u] = 'b';
}

void DFS(int k)
{
	int i;
	for(i=1;i<=n;i++) {
			c[i] = 'w';
	}
	//printf("when leaving %d ",k);
	if(k==1)
		DFSvisit(2,k);
	else DFSvisit(1,k);
	//printf("\n");
}

int main()
{
	
	int max,m,u,v,k,j,i,size=0;
	scanf("%d%d",&n,&m);
	max=0;
	while(n!=0 && m!=0) {
		
		for(i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			adj[u][v]=true;
			adj[v][u]=true;
			a[i]=v;
			b[i]=u;
		}
		size=0;
		for(k=1;k<=n;k++) {
			max=0;
			//for(i=1;i<=n;i++)a[i]=adj[i][k];
			//for(i=1;i<=n;i++)b[i]=adj[k][i];
            //for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i==k || j==k)adj[i][j]=0;
            DFS(k);
            //for(i=1;i<=n;i++)adj[i][k]=a[i];
			//for(i=1;i<=n;i++)adj[k][i]=b[i];
			//for(i=1;i<=n;i++)printf("%c ",c[i]);
			//printf("\n");
			for(i=1;i<=n;i++)if(i!=k && c[i]!='b'){max=1;break;}
			if(max==1)size++;
		}
		printf("%d\n",size);
		for(i=0;i<m;i++){adj[a[i]][b[i]]==false;adj[b[i]][a[i]]==false;}
		scanf("%d%d",&n,&m);
		//articulation points
	}
	return 0;
}
