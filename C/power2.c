# include <stdio.h>
# include <conio.h>
# include <math.h>
int powerof2(int n) {
	return n && !(n & (n-1));
}
int main()
{
	int n;
	//scanf("%d",&n);
	//printf("%d\n",powerof2(n));
    //printf("%d\n",100000 && 5777777);
    double r;
    double a,b=1.0;
    printf("%f\n",11e-1);
    for(a=0.0; r<11e-1; a+=0.1) printf("*");
    for (a=0.0; (a-b)<11e-7; a+=0.1) printf("*");
	getch();
	return 0;
}
