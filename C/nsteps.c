# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int x[10001][3];
	int k = 0 , y=0 , i=0 , j=0 , n , X , Y;
	while(k<=10000) {
		x[k][0] = i;
		x[k][1] = j;
		x[k][2] = k;
		k++;
		if(y==0||y==2){i++;j++;y++;}
		else if(y==1){i++;j--;y++;}
		else if(y==3){i--;j++;y=0;}
	}
	scanf("%d" , &n);
	while(n--) {
		j = 0;
		scanf("%d%d" , &X , &Y);
		for(i=0;i<10001;i++) {
			if(x[i][0] == X && x[i][1] == Y){j=1;break;}
		}
		if(j==1)printf("%d\n" , x[i][2]);
		else printf("No Number");
	}
	getch();
	return 0;
}
