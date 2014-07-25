#include <cstdio>
#include <algorithm>
#include <string.h>
#include <conio.h>
using namespace std;

int main(){
	int len1, len2, i, j, k, stop;
	char s1[100], s2[100];
	int s3[100], s4[100];
	scanf("%s", &s1);
	scanf("%s", &s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	for(i = 0; i < len2; i++){
		s4[i] = (int)(s2[i] - 'a');
	}
	stop = 0;
	sort(s4, s4+len2);
	for(i = 0; i <= len1-len2; i++){
		for(j = 0; j < len2; j++){
			s3[j] = (int)(s1[i+j] - 'a');
		}
		sort(s3, s3+len2);
		stop = 0;
		for(k = 0; k < len2; k++){
			if(s3[k] != s4[k])stop = 1;
		}
		if(stop == 0){
			printf("True\n");
			//getch();

		}
		//for(k = 0; k < len2; k++)printf("%d ", s3[k]);
		//printf("\n");
	}
	printf("False\n");
	for(i = 0; i < len2; i++)printf("%d ", s4[i]);
	getch();
	return 0;
}
