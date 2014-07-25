/*# include <cstdio>
# include <conio.h>
# include <cmath>
# include <algorithm>
# include <vector>
# include <csignal>
using namespace std;
int main()
{
	vector <char> v (1000000001);
	int q,m,n,i,t,j,s,check,max=0;
	scanf("%d" , &t);
	for(q=0;q<t;q++) {
		check=0;
		scanf("%d" , &m);
		scanf("%d" , &n);
		if(max>=n)check=1;
		else max=n;
  		//s = n+1;
		//char c[s];
		//v.push_back('0');
		if(check == 0) {
			for(i=1;i<=n;i++)v[i]='1';
			v[1]='0';
			if(n>=4)
			for(i=4;i<=n;i+=2)v[i] = '0';
			for(j=3;j<sqrt(n);j++) {
				if(v[j] == '1') {
					s = 0;
					for(i=2;i<sqrt(j);i++)if(j%i==0)s++;
					if(s==0) {
						if(n>=j*j) {
							for(i=j*j;i<=n;i+=j)v[i] = '0';
						}
					}
					else v[j] = '0';
				}
			}
		}
		for(i=m;i<=n;i++)if(v[i] == '1')printf("%d\n" , i);
	}
	getch();
	return 0;
}*/
#include<conio.h>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	int m, n;
	int i,j,f,p;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
	    int primes[n-m+1];
	    for(i=0;i<n-m+1;i++)primes[i] = 0;
        for(p=2;p*p<=n;p++)
		{
			f=m/p;
			f*=p;
 			for(j=f;j<=n;j+=p)
			{
				if(j!=p&&j>=m)
					primes[j-m]=1;
			}
		}

		for(i=0;i<n-m+1;i++)
		{
			if(primes[i]==0&&m+i!=1)
				printf("%d\n", m+i);
		}
	}
	getch();
	return 0;

}
