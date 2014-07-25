#include <stdio.h>
#include <conio.h>
int main() {
	int n, m, i;
	int arr[100001] = {0};
	scanf("%d", &n);
	
	for(i = 0; i < n-1; i++){
		scanf("%d", &m);
		arr[m] = -999;
	}
	for(i = 1; i <= n; i++){
		if(arr[i] != -999){
			printf("%d\n", i);
			break;
		}
	}
	getch();
	return 0;
}
