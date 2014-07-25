#include <cstdio>
#include <cstdlib>
# include <vector>
# include <conio.h>
using namespace std;
int main(){
    vector <bool> v (1000000001);
    unsigned long long int i,j;
    int z = 1;
    for (i=3;i<100000000;i+=2)
        if (!v[i])
            for (j=i;i*j<100000000;j++)
                v[i*j]=true;
	int count=-1;
    for (i=2;i<100000000;i++)
        if (!v[i]) {
            	count++;
			if(count%100==0|| count==0)printf("%d\n" , i);
        }
       // printf("%d",z&1);
getch();
return 0;
}
