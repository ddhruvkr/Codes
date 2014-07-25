# include <stdio.h>
# include <conio.h>
//int s=0,a,b,c;
long long int divide(long long int x)
{
	long long int s=0;
	//int a,b,c;
	//a=x/2;b=x/3;c=x/4;
	if(x/2+x/3+x/4>x) {
		s=s+divide(x/2);//printf("1 %d\n", s);
		s=s+divide(x/3);//printf("2 %d \n", s);
		s=s+divide(x/4);//printf("3 %d \n", s);
	}
	else return x;
	return s;
}
int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF) {//scanf("%d" , &n);
		n=divide(n);
		printf("%lld\n" , n);
    }
	getch();
	return 0;
}
