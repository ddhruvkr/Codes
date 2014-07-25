# include <stdio.h>
int sheep = 0, wolf = 0, n, m;
char s[251][251];
void dfs(int i, int j) {
	if(s[i][j] == 'k')sheep++;
	else if(s[i][j] == 'v')wolf++;
	s[i][j] = '#';
	if(i > 0 && s[i - 1][j] != '#')dfs(i - 1, j);
	if(i + 1 < n && s[i + 1][j] != '#')dfs(i + 1, j);
	if(j > 0 && s[i][j - 1] != '#')dfs(i, j - 1);
	if(j + 1 < m && s[i][j + 1] != '#')dfs(i, j + 1);
}
int main() {
	int i, j, ssur = 0, wsur = 0;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++)scanf("%s" , s[i]);
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(s[i][j] != '#') {
				dfs(i,j);
				if(wolf >= sheep)wsur = wsur + wolf;
				else ssur = ssur + sheep;
				wolf = 0;
				sheep = 0;
			}
		}
	}
	printf("%d %d\n", ssur, wsur);
	return 0;
}
