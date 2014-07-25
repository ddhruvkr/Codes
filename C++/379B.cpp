#include <stdio.h>
#include <conio.h>

int main() {
	int n, i, x, low, high;
	char s[1000004];
	int a[305];
	scanf("%d", &n);
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	low = 0;
	i = n-1;
	while(1) {
		if(a[i] <= 0)i--;
		else break;
	}
	high = i;
	x = 0;
	
	while(1) {
		if(a[low] == 0){
			if(low == high)break;
			low++;
			s[x++] = 'R';
		}
		else {
			a[low]--;
			s[x++] = 'P';
			if(low == high && a[low] == 0)break;
			if(low != n-1 && a[low] != 0) {
				s[x++] = 'R';
				if(a[low+1] != 0){
					a[low+1]--;
					s[x++] = 'P';
				}
				s[x++] = 'L';
			}
			else if(low != n-1 && a[low] == 0) {
				s[x++] = 'R';
				low++;
			}
			else if(low != 0) {
				s[x++] = 'L';
				s[x++] = 'R';
			}
		}
		s[x] = '\0';
	}
	printf("%s\n", s);
	getch();
	return 0;
}
