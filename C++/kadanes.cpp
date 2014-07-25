#include <stdio.h>
#include <conio.h>

//int a[] =  {1, -2, 3, 10, -4, 7, 2, -5};
int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};

void display(int ind, int p[8]) {
	if(p[ind] == ind){
		printf("%d", a[ind]);
		return;
	}
	else {
		//printf("dd\n");
		display(p[ind], p);
		printf(" , %d", a[ind]);
	}
}

void kadane(int p[8]) {
	int max, sum[8], ind = 0;
	max = sum[0] = a[0];
	for(int i = 1; i < 8; i++) {
		if(sum[i - 1] + a[i] > a[i]){
			sum[i] = sum[i - 1] + a[i];
			p[i] = i - 1;
		}
		else sum[i] = a[i];
		if(max < sum[i]){
			max = sum[i];
			ind = i;
		}
	}
	for(int i = 0; i < 8; i++)printf("%d ", sum[i]);
	printf("\n");
	printf("%d\n", max);
	for(int i = 0; i < 8; i++)printf("%d ", p[i]);
	printf("\n");
	printf("%d\n", p[ind]);
	display(ind, p);
	
}

int main() {
    int p[8];
	for(int i = 0; i < 8; i++)p[i] = i;
	kadane(p);
	getch();
	return 0;
}
