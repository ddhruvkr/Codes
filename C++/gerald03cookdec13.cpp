#include <stdio.h>
char str[90000000];
 
int main() {
	int t, i, n, k = 1;
	int l[1005], r[1005];
	scanf("%d", &t);
	while(t--) {
		k = 1;
		scanf("%d", &n);
		for(i = 0; i < n; i++)scanf("%d%d", &l[i], &r[i]);
		for(i = 0; i < n-1; i++) {
			while(l[i] != l[i+1] || r[i] != r[i+1]) {
				if(l[i] < l[i+1] && l[i]+1 != r[i]) {
                    str[k++]='L';
                    str[k++]='+';
                    l[i]++;
				}
				else if(l[i] > l[i+1] && l[i]-1 != r[i]) {
                    str[k++]='L';
                    str[k++]='-';
                    l[i]--;
				}
                else if(r[i] < r[i+1] && r[i]+1 != l[i]) {
                    str[k++]='R';
                    str[k++]='+';
                    r[i]++;
				}
				else if(r[i] > r[i+1] && r[i]-1 != l[i]) {
                    str[k++]='R';
                    str[k++]='-';
                    r[i]--;
				}
				/*else if(l[i] > l[i+1]) {
					str[k++]='L';
					str[k++]='-';
					l[i]--;
				}
				else if(l[i] < l[i+1]) {
					str[k++]='L';
					str[k++]='+';
					l[i]++;
					//printf("rsr");
				}
				else if(r[i] > r[i+1]) {
					str[k++]='R';
					str[k++]='+';
					r[i]++;
				}
				else if(r[i] > r[i+1]) {
					str[k++]='R';
					str[k++]='-';
					r[i]--;
				}*/
			}
		}
		str[k] = '\0';
		printf("%d\n", k/2);
		for(i=1;i<k;i++)
		printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}
