#include <cstdio>
#include <cstdlib>
# include <vector>
# include <conio.h>
using namespace std;
int main(){
    vector <bool> v (100000000>>1);
     int i,j;
    int z = 1;
    for (i=3;i<10001;i+=2)
        if (!v[(i-3)>>1])
            for (j=i*i;j<99998954;j+=2*i)

             v[(j-3)>>1]=1;

	int count=0;
	printf("2\n");
    for (i=0;2*i<(99998954);i++)
        if (!v[i]) {
            	count++;
			if(count%100==0)printf("%d\n" , 2*i+3);
        }
getch();
return 0;
}
