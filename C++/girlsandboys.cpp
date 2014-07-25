# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int g,b,max,min,s;
	scanf("%d%d" , &g , &b);
	while(g!=-1 && b!=-1) {
		if(b==0 && g==0)printf("0\n");
		else if(b==g)printf("1\n");
		//else if(b == 0)printf("%d\n" , g);
		//else if(g == 0)printf("%d\n" , b);
		else {
			if(b > g){max = b;min =g;}
			else {max = g;min =b;}
			if(max%(min+1) == 0)printf("%d\n" , max/(min+1));
			else printf("%d\n" , (max/(min+1)+1));
		}
		scanf("%d%d" , &g , &b);
	}
	getch();
	return 0;
}
