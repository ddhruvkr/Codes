#include <stdlib.h>	// for itoa() call
#include <stdio.h>	// for printf() call
int main()
{
	int num = 123;
	char buf[5];
	int e=2,d;
	float x=3/2;
	printf("%.8f\n",x);
	while(num!=0)
	{
	    d=num%10;
	    buf[e]=(char)(((int)'0')+d);
	    e--;
	    num=num/10;
	}
	//buf[3]='\0';
	printf("%s\n", buf);
	return 0;
}
