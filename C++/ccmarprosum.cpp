#include <stdio.h>
int a[3000000];
int main() {
	int t, n, i, noofones, v, noofzero, nooftwo;
	long long int total, pairs;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		pairs = 0;
		noofones = 0;
		total = 0;
		noofzero = 0;
		nooftwo = 0;
		for(i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			total += i-1;
			if(a[i] == 1) {
				noofones++;
				pairs += i - 1;
			}
			else if(a[i] == 0){
				noofzero++;
				pairs += i - 1;
			}
			else if(a[i] == 2){
                pairs += nooftwo;
                pairs += noofones;
				pairs += noofzero;
                nooftwo++;
			}
			else {
				pairs += noofones;
				pairs += noofzero;
			}
		}
		printf("%lld\n", total - pairs);
	}
	return 0;
}
