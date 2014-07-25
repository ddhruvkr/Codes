#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int> a[2000];
int visited[2000];
int color[2000];
queue<int> Q;

int bfs(int u)
{
    int flag=1;
    visited[u]=1;
   	color[u]=1;
    Q.push(u);
    while(!Q.empty())
    {
    	u=Q.front();
        Q.pop();
		for(int i=0;i<a[u].size();i++)
 		{
			int v=a[u][i];
     		if(color[v]==color[u])
     		{
				flag=0;
     		}
     		if(visited[v]==0)
    		{
				visited[v]=1;
     			color[v]=3-color[u];
  				Q.push(v);
    		}
 		}
	}
 	return flag;
}
int main()
{
    int N,M,u,v,ans,flag,k;
    int t;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
   {
   scanf("%d",&N);
    scanf("%d",&M);
    flag=1;
    for(int i=0;i<N;i++) a[i].clear();
    while(M--)
    {
        scanf("%d",&u);
        scanf("%d",&v);
        a[v].push_back(u);
        a[u].push_back(v);
    }
    memset(visited,0,4*N);
    memset(color,0,4*N);
    for(int i=0;i<N;i++)
   	{
        if(visited[i]==0)
         ans=bfs(i);
         if(ans==0) {
         		flag=0;
         		break;
		 }
    }
    if(flag==0)
    printf("Scenario #%d:\nSuspicious bugs found!\n",k);
    else
    printf("Scenario #%d:\nNo suspicious bugs found!\n",k);
	}
	return 0;
}
