#include <stdio.h>
#include <conio.h>

void merge(int arr[10], int l, int m, int r) {
	int temp[10];
	int j, x, i;
	j = m + 1;
	x = l;
	for(i = l; i <= m && j <= r;) {
		if(arr[i] <= arr[j]) {
			temp[x] = arr[i];
			x++;
			i++;
		}
		else {
			temp[x] = arr[j];
			x++;
			j++;
		}
	}
	if(i <= m) {
		while(i <= m) {
			temp[x] = arr[i];
			i++;
			x++;
		}
	}
	else if(j <= r) {
        while(j <= r) {
			temp[x] = arr[j];
			j++;
			x++;
		}
	}
	for(i = l; i <= r; i++)arr[i] = temp[i];
	return;
}

void divide(int arr[10], int l, int r) {
	if(l < r) {
		int m = (l + r)/2;
		divide(arr, l, m);
		divide(arr, m+1, r);
		merge(arr, l, m, r);
	}
	return;
}

int main() {
	int i;
    int arr[10] = {45, 76, 62, 63, 66, 25, 99, 65, 89, 02};
    divide(arr, 0, 9);
    for(i = 0; i <= 9; i++)printf("%d ", arr[i]);
    printf("\n");
    getch();
    return 0;
}
