# include <cstdio>
using namespace std;
int main()
{
	int t,h,a,count;
    scanf("%d" , &t);
	while(t--) {
		scanf("%d%d",&h,&a);
		count=0;
		while(h>0 && a>0) {
			h+=3;
			a+=2;
			count++;
            if(h-5>0 && a-10>0) {
				h-=5;
				a-=10;
			}
		    else {
				h-=20;
				a+=5;
			}
			if(a>0 && h>0)count++;
		}
		printf("%d\n" , count);
	}
	return 0;
}
