# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int n;
	scanf("%d" , &n);
	if(n%10 == 0) {
		printf("2\n");
		//printf("1\n");
	}
	else {
		printf("1\n");
		n =n%10;
		printf("%d\n" , n);
	}
	getch();
	return 0;
}
