#include <cstdio>
using namespace std;

char grid[16][16];
int dp[16][16];

int main() {
	int n, i, j, d;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%s", grid[i]);
	dp[n-1][n-1] = 1;
	for(i = n-1; i>=0; i--) {
		for(j = n-1; j >= 0; j--) {
			if(grid[i][j] != '0') {
				d = grid[i][j]-'0';
				if(j + d < n) dp[i][j] += dp[i][j+d];
				if(i + d < n) dp[i][j] += dp[i+d][j];
			}
		}
	}
	printf("%d", dp[0][0]);
	return 0;
}
# include <cstdio>
# include <stack>
# include <conio.h>
using namespace std;
int main()
{
	stack<int> s;
	stack<int> s1;
	stack<int> s2;
	int n,i,j,i1,j1,x=0;
	scanf("%d" , &n);
	char c[n][n];
	int a[n][n];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{c[i][j] = 'n';}
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d" , &a[i][j]);
	a[n-1][n-1] = 1;
	s.push(a[0][0]);
	s1.push(0);
	s2.push(0);
	int jk=0;
	while(!s.empty()) {
		//printf("%d %d %d\n" , s.top() , s1.top() , s2.top());
		i1 = s1.top();
		j1 = s2.top();
		for(i=0;i<n;i++)for(j=0;j<n;j++)if(i!=i1 && j>=j1)c[i][j] = 'n';
		//if(jk==1)printf("%d %d\n" ,i1,j1);
		if(c[i1][j1] == 'n') {
			if(s.top() + j1 >= n || (s.top() + j1 < n && a[i1][j1 + s.top()] == 0 )) {
				c[i1][j1] = 'y';
				printf("dhruv");
				printf("%d %d\n" , i1,j1);
			}
			else if(s.top() + j1 < n) {
				c[i1][j1] = 'y';
				printf("dddddhruv");
				j1 = j1 + s.top();
				printf("%d %d\n" , i1,j1);
				if(i1 == n-1 && j1 == n-1){x++;}
				else {
					s.push(a[i1][j1]);
					s1.push(i1);
					s2.push(j1);
				}
			}
		}
		else {
			if(s.top() + i1 >= n || (s.top() + i1 < n && a[i1 + s.top()][j1] == 0)) {
				s.pop();
				s1.pop();
				s2.pop();
				printf("yeah\n");
			}
   			else if(s.top() + i1 < n) {
				i1 = i1 + s.top();
				if(i1 == n-1 && j1 == n-1){x++;printf("shantanu");s.pop();s1.pop();s2.pop();printf("%d %d %d\n" , s.top() , s1.top() , s2.top());
				printf("%c %c %c %c\n", c[0][0] ,c[0][1],c[1][0] , c[1][1]);jk=1;
				}
				else {
					s.pop();
					s1.pop();
					s2.pop();
					s.push(a[i1][j1]);
					s1.push(i1);
					s2.push(j1);
				}
			}
		}
	}
	printf("%d\n" , x);
	getch();
	return 0;
}
