#include <stdio.h>
#include <conio.h>
int main() {
	int D, a, b, c, d, e, f, g, h, i, j, k, sum;
	int arr[3][3], ba[3][3];
	int ab[10];
	for(j = 0; j < 3; j++)
	for(k = 0; k < 3; k++)
	scanf("%d", &arr[j][k]);
	for(a = 0; a < 2; a++) {
		ab[1] = a;
		for(b = 0; b < 2; b++) {
			ab[2] = b;
			for(c = 0; c < 2; c++) {
				ab[3] = c;
				for(d = 0; d < 2; d++) {
					ab[4] = d;
					for(e = 0; e < 2; e++) {
						ab[5] = e;
                        for(f = 0; f < 2; f++) {
							ab[6] = f;
							for(g = 0; g < 2; g++) {
								ab[7] = g;
								for(h = 0; h < 2; h++) {
									ab[8] = h;
									for(i = 0; i < 2; i++) {
										ab[9] = i;
										for(j = 0; j < 3; j++) {
											for(k = 0; k < 3; k++) {
												ba[j][k] = arr[j][k];
											}
										}
										if(ab[1] == 1) {
											ba[0][0]+= 1;
											ba[0][1]+= 1;
											ba[1][0]+= 1;
											ba[1][1]+= 1;
										}
										if(ab[2] == 1) {
											ba[0][0]+= 1;
											ba[0][1]+= 1;
											ba[0][2]+= 1;
										}
										if(ab[3] == 1) {
											ba[0][1]+= 1;
											ba[0][2]+= 1;
											ba[1][1]+= 1;
											ba[1][2]+= 1;
										}
										if(ab[4] == 1) {
											ba[0][0]+= 1;
											ba[1][0]+= 1;
											ba[2][0]+= 1;
										}
										if(ab[5] == 1) {
											ba[0][1]+= 1;
											ba[1][0]+= 1;
											ba[1][1]+= 1;
											ba[1][2]+= 1;
											ba[2][1]+= 1;
										}
										if(ab[6] == 1) {
											ba[0][2]+= 1;
											ba[1][2]+= 1;
											ba[2][2]+= 1;
										}
										if(ab[7] == 1) {
											ba[1][0]+= 1;
											ba[1][1]+= 1;
											ba[2][0]+= 1;
											ba[2][1]+= 1;
										}
										if(ab[8] == 1) {
											ba[2][0]+= 1;
											ba[2][1]+= 1;
											ba[2][2]+= 1;
										}
										if(ab[9] == 1) {
											ba[1][1]+= 1;
											ba[1][2]+= 1;
											ba[2][1]+= 1;
											ba[2][2]+= 1;
										}
										sum = 0;
										for(j = 0; j < 3; j++) {
											for(k = 0; k < 3; k++) {
												if(ba[j][k] % 4 == 0)sum++;
											}
										}
										if(sum == 9) {
											for(D = 1; D < 10; D++) {
												if(ab[D] == 1)printf("%d ", D);
											}
											printf("\n");
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
