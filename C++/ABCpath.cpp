/*# include <cstdio>
using namespace std;
int main()
{
	int q=0,max,i,j,h,w,found;
	char ch;
	char s[50];
	char hw[52][52];
	int a[52][52];
	scanf("%d%d",&h,&w);
	while(h!=0 && w!=0) {
		found=0;
		q++;
		for(i=0,j=0;i<=h+1;i++)hw[i][j]='$';
		for(i=0,j=w+1;i<=h+1;i++)hw[i][j]='$';
		for(i=0,j=0;i<=w+1;i++)hw[j][i]='$';
		for(i=0,j=h+1;i<=w+1;i++)hw[j][i]='$';
        for(i=0;i<=51;i++)for(j=0;j<=51;j++)a[i][j]=0;
		for(i=1;i<=h;i++){
			scanf("%s",s);
			for(j=1;j<=w;j++)hw[i][j]=s[j-1];
		}
		for(i=1;i<=h;i++) {
			for(j=1;j<=w;j++) {
				if(ch=='Z'){j=w+1;i=h+1;}
				else if(found==0)if(hw[i][j]=='A'){found==1;a[i][j]=1;ch='A';}
				else {
					if((int)hw[i][j]-(int)hw[i-1][j-1]==1 && a[i-1][j-1]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i-1][j-1]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i-1][j]==1 && a[i-1][j]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i-1][j]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i-1][j+1]==1 && a[i-1][j+1]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i-1][j+1]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i][j-1]==1 && a[i][j-1]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i][j-1]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i][j+1]==1 && a[i][j+1]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i][j+1]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i+1][j-1]==1 && a[i+1][j-1]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i+1][j-1]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i+1][j]==1 && a[i+1][j]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i+1][j]+1;ch++;}
                    if((int)hw[i][j]-(int)hw[i+1][j+1]==1 && a[i+1][j+1]+1>a[i][j] && (int)hw[i][j]-(int)ch==1){a[i][j]=a[i+1][j+1]+1;ch++;}
				}
			}
		}
		max=0;
		for(i=1;i<51;i++)for(j=1;j<51;j++)if(max<a[i][j]){max=a[i][j];ch=hw[i][j];}
		printf("Case %d: %d\n",q,max);
		scanf("%d%d",&h,&w);
	}
	return 0;
}*/
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
int main()
{
	int r,c,x,y,i,j,q1;
	char s[50][50];
	int a[50][50],visited[50][50];
	int m1[]={-1,0,1,1,1,0,-1,-1};
	int m2[]={-1,-1,-1,0,1,1,1,0};
	int max;
	queue <pair<int,int> > q;
	pair <int,int> p;
	scanf("%d%d",&r,&c);
	q1=1;
	while(r!=0 || c!=0)
	{
		max=0;
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
				}
			}
		}

		while(!q.empty())
		{
			p=q.front(); q.pop();
			for(i=0;i<=7;i++)
			{
				x=m1[i]+p.first; y=m2[i]+p.second;
	//			printf("%d %d %d %d\n",x,y,s[x][y],(1+s[p.first][p.second]));
				if(x>=0 && x<r && y>=0 && y<c && (s[x][y]==(1+s[p.first][p.second])))
				{
					if(visited[x][y]==0)
					{
						a[x][y]=(1+a[p.first][p.second]);
						visited[x][y]=1;
						if(max<a[x][y]) max=a[x][y];
						q.push(make_pair(x,y));
					}
				}
			}
		}

		printf("Case %d: %d\n",q1,max);
		scanf("%d%d",&r,&c);
		q1++;
	}
	return 0;
}
