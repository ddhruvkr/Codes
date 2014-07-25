# include <stdio.h>
# include <string.h>
int main() {
	int j, k, l1, l2;
	char s[1024], t[1024], c[128][2];
	char i;
    while(scanf("%s %s", s, t) == 2) {
		for(i = 'a'; i <= 'z'; i++) {
			c[i][0] = 0;
			c[i][1] = 0;
		}
		l1 = strlen(s);
		l2 = strlen(t);
		for(j = 0; j < l1; j++)c[s[j]][0]++;
		for(j = 0; j < l2; j++)c[t[j]][1]++;
		for(i = 'a'; i <= 'z'; i++) {
			if(c[i][0] != 0 && c[i][1] != 0) {
				if(c[i][0] > c[i][1])
					for(k = 0; k < c[i][1]; k++)printf("%c" , i);
					else for(k = 0; k < c[i][0]; k++)printf("%c" , i);
			}
		}
		printf("\n");
	}
	return 0;
}
