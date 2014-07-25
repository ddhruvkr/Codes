#include <cstdio>
#include <conio.h>
using namespace std;
int main()
{
 	long long n,a[46323377618],index,temp,i,t;
 	scanf("%ld",&t);
 	while(t--)
 	{
 		a[0]=1;
 		index=0;
 		scanf("%ld",&n);
 		for(;n>=2;n--)
 		{
 			temp=0;
 			for(i=0;i<=index;i++)
 			{
 				temp=(a[i]*n)+temp;
 				a[i]=temp%10;
 				temp=temp/10;
 			}
 			while(temp>0)
 			{
 				a[++index]=temp%10;
 				temp=temp/10;
 			}
 		}
 		//for(i=index;i>=0;i--)
 		printf("%ld",index+1);
 		printf("\n");
 	}
	getch();
	return 0;
}
