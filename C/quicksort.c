#include <stdio.h>
#include <conio.h>

int partition(int arr[10], int l, int r) {
	int i = l - 1, j, temp;
	int x = arr[r];
	for(j = l; j < r; j++) {
		if(x >= arr[j]) {
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
    temp = arr[r];
	arr[r] = arr[i+1];
	arr[i+1] = temp;
	return i + 1;
}

void quicksort(int arr[10], int l, int r) {
	if(r > l) {
		int q = partition(arr, l, r);
		quicksort(arr, l, q-1);
		quicksort(arr, q+1, r);
	}
}

int main() {
	int i;
    int arr[10] = {45, 76, 62, 63, 66, 25, 99, 65, 89, 02};
    quicksort(arr, 0, 9);
    for(i = 0; i < 10; i++)printf("%d ", arr[i]);
    printf("\n");
    getch();
    return 0;
}

