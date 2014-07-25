# include <cstdio>
# include <conio.h>
# include <iostream>
using namespace std;
int q[1001][1001];
int main()
{
	int k,m,n,a,b,x1,y1,c,i,j,d,x2,y2;
	char s[1001];
	char ch;
	char dd[5];
	dd[0]='W';
	dd[1]='N';
	dd[2]='E';
	dd[3]='S';
	dd[4]='W';
	scanf("%d%d",&m,&n);
	/*for(i=0;i<m;i++) {
		scanf("%s",s[i]);
		for(j=0;j<n;j++) {
			if(s[i][j]=='N')q[i][j]=1;
			else if(s[i][j]=='E')q[i][j]=2;
			else if(s[i][j]=='S')q[i][j]=3;
			else if(s[i][j]=='W')q[i][j]=4;
		}
	}*/
	for (i = 0; i < m; ++i) {
                cin>>s;
                for (j = 0; j < n; ++j) {
                    	if(s[j]=='N')q[i][j]=1;
			else if(s[j]=='E')q[i][j]=2;
			else if(s[j]=='S')q[i][j]=3;
			else if(s[j]=='W')q[i][j]=4;
                      /*  switch (s[j]) {
                                case 'N':{
                                        q[i][j] = 1;
                                        break;
                                }
                                case 'E':{
                                        q[i][j] = 2;
                                        break;
                                }
                                case 'S':{
                                        q[i][j] = 3;
                                        break;
                                }
                                case 'W':{
                                        q[i][j] = 4;
										break;
                                }
                        }*/
                }
        }

	scanf("%d",&c);
	while(c--) {
		cin >> ch;
		if(ch=='D') {
			scanf("%d%d",&a,&b);
			printf("%c\n",dd[q[a-1][b-1]]);
		}
		else if(ch=='C'){
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&d);
			for(i=x1-1;i<x2;i++) {
				for(j=y1-1;j<y2;j++) {
					if(d==0) {
						q[i][j]=(q[i][j]+1)%4;
						//if(q[i][j]==5)q[i][j]=1;
					}
					else if(d==1) {
                        q[i][j]=(q[i][j]+3)%4;
                        //if(q[i][j]==0)q[i][j]=4;
					}
				}
			}
		}
	}
	getch();
	return 0;
}
