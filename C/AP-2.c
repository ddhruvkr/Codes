#include <stdio.h>
#include <conio.h>
int main()
{
    int n,i,z,d,f;
    long long a,b,c,x;
    scanf("%d",&n);
    while(n--) {
    scanf("%lld %lld %lld",&a,&b,&c);
    x=(c/(a+b));
    if(((a+b)*x)==c)f=(2*x);
    else f=(2*x+1);
    printf("%d\n",f);
    d=((b-a)/(f-5));
    z=(a-2*d);
    for(i=0;i<f;i++)
    {
        printf("%d ",z+i*d);
    }
    printf("\n");
	}
    getch();
    return 0;
}
