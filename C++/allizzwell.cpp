#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
int main()
{
	int r,c,x,y,i,j,n,t=0;
	char d[]={'A','L','L','I','Z','Z','W','E','L','L'};
	char s[100][50];
	int a[100][100],visited[100][100];
	int m1[]={-1,0,1,1,1,0,-1,-1};
	int m2[]={-1,-1,-1,0,1,1,1,0};
	int max;
	queue <pair<int,int> > q;
	queue <int> q1;
	pair <int,int> p;
	scanf("%d%d",&r,&c);
	t=1;
	while(r!=0 || c!=0)
	{
		max=0;
		n=0;
		memset(a,0,sizeof(a));
		memset(visited,0,sizeof(visited));
		for(i=0;i<r;i++)
			scanf("%s",&s[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(s[i][j]=='A')
				{	a[i][j]=1; max=1;
					q.push(make_pair(i,j));
					q1.push(n);
				}
			}
		}

		while(!q.empty())
		{
			p=q.front(); q.pop();
			r=q1.front();q1.pop();
			for(i=0;i<=7;i++)
			{
				x=m1[i]+p.first; y=m2[i]+p.second;
	//			printf("%d %d %d %d\n",x,y,s[x][y],(1+s[p.first][p.second]));
				if(x>=0 && x<r && y>=0 && y<c && (s[x][y]==d[r]))
				{
					if(visited[x][y]==0)
					{
						a[x][y]=(1+a[p.first][p.second]);
						visited[x][y]=1;
						if(max<a[x][y]) max=a[x][y];
						q.push(make_pair(x,y));
						q1.push(++r);
					}
				}
			}
		}
		if(r>=9)
		printf("Yes\n");
		else printf("No\n");
		scanf("%d%d",&r,&c);
		t++;
	}
	return 0;
}
