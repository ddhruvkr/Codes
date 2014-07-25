# include<cstdio>
# include<conio.h>
using namespace std;
int main()
{
	int i,j,k,q,l,m;
	int c[] = {2,3,8};
	//printf("enter the value of coins u have\n");
	//scanf("%d" , &q);
	//int c[q];
	int p[20][10];
	//for(i=0;i<q;i++)scanf("%d" , &c[i]);
	//int c[
	int min[20];
	for(i = 1; i < 20; i++)min[i] = 999999;
	min[0] = 0;
	for(i = 1; i < 20; i++) {
		for(j = 0; j <= 2; j++){
            k = 3;
            m = 0;
			while(k--)if(i == c[k]){
				min[i] = 1;
				p[i][0] = i;
				p[i][1] = -1;
				m = 1;
			}
			if(m == 0) {
				if(c[j] <= i && min[i-c[j]] + 1 < min[i]){
					min[i] = min[i - c[j]] + 1;//for number of coins
					l = 0;
					while(p[i - c[j]][l] != -1) {
						p[i][l] = p[i - c[j]][l];//for coins
						l++;
					}
					p[i][l] = c[j];
					p[i][l+1] = -1;
				}
			}
		}
		printf("%d    %d     " , i , min[i]);
		l = 0;
		if(min[i]==999999)printf("Not possible");
		else
		while(p[i][l] != -1){printf("%d ",p[i][l]);l++;}
		printf("\n");
	}
	getch();
	return 0;
}
