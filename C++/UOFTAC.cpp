# include <cstdio>
int main()
{
	int t,h,w,N,i,j,count,x,m,n;
	char ch[2];
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&h,&w,&N);
		char c[h+2][w];
		x=0;
		count=0;
		for(i=1;i<=h;i++)scanf("%s",&c[i]);
		for(i=h+1,j=0;j<w;j++)c[i][j]='$';
		i=0;j=0;
		for(x=0;x<N;x++) {
			scanf("%s",ch);
			if(ch[0]=='L') {
				if(j!=0 && i==0) {
					m=i;n=j-1;
					while(c[m+1][n]=='E'){m++;}
					i=m;j=n;
				}
				else if(j!=0 && i!=0) {
					if(c[i][j-1]=='D' || c[i][j-1]=='E') {
                    	m=i;n=j-1;
						while(c[m+1][n]=='E'){m++;}
						i=m;j=n;
					}
					else if(c[i][j-1]=='T') {
						c[i][j-1]='E';
						count++;
						m=i;n=j-1;
						while(c[m+1][n]=='E'){m++;}
						i=m;j=n;
					}
				}
			}
            else if(ch[0]=='R') {
				if(j!=w-1 && i==0) {
					m=i;n=j+1;
					while(c[m+1][n]=='E')m++;
					i=m;j=n;
				}
				else if(j!=w-1 && i!=0) {
					if(c[i][j+1]=='D' || c[i][j+1]=='E') {
                    	m=i;n=j+1;
						while(c[m+1][n]=='E'){m++;}
					//if(br==0)j++;
						i=m;j=n;
						//printf("%d %d\n",i,j);
					}
					else if(c[i][j+1]=='T') {
						c[i][j+1]='E';
						count++;
						m=i;n=j+1;
						while(c[m+1][n]=='E'){m++;}
					//if(br==0)j++;
						i=m;j=n;
						//printf("%d %d\n",i,j);
					}
				}
			}
			else if(ch[0]=='D') {
				if(i!=h) {
					if(c[i+1][j]=='D') {
                    	i++;
						while(c[i+1][j]=='E'){i++;}
						//printf("%d %d\n",i,j);
					}
					else if(c[i+1][j]=='T') {
						count++;
						i++;
						c[i][j]='E';
						while(c[i+1][j]=='E'){i++;}
						//printf("%d %d\n",i,j);
					}
				}
			}
		}
		printf("%d\n",count);
		//for(i=1;i<=h;i++){for(j=0;j<w;j++)printf("%c ",c[i][j]);printf("\n");}
		//printf("%d %d\n",i,j);
	}
	return 0;
}
