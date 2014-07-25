# include <cstdio>
# include <conio.h>
# include <map>
using namespace std;
map < int, long long > M;
map < int, long long > :: iterator it;

long long cube(int i)
{
	long long s=1;
	int j;
	for(j=0;j<3;j++) {
		s=s*i;
		s=s%1000000003;
	}
	it = M.end();
	M.insert(it, pair < int, long long > (i, s));
	return s;
}
int main()
{
	int t,n,i,j;
	long long d,s;
	scanf("%d" , &t);
	while(t--) {
		d=0;
		scanf("%d" , &n);
		j=n;
		for(i=1;i<=n;i++) {
			if(M.find(i)==M.end())s=cube(i);
			//printf("s= %lld\n" , s);
			else s=(*it).second;
			//printf("s= %lld\n" , s);
			s=s%1000000003;
			s=j*s;
			j--;
			s=s%1000000003;
			d=d+s;
			d=d%1000000003;
		}
		d=d%1000000003;
		printf("%lld\n" , d);
	}
	getch();
	return 0;
}
