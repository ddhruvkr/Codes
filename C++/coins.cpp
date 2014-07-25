#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

//map :: n with f(n)
map < long long, long long > M;
map < long long, long long > :: iterator it;

long long func(long long n)
{
	if(n==0) return 0;
	it = M.find(n);
	if(it==M.end())
	{
		long long v = max(n, func(n/2) + func(n/3) + func(n/4));
		M.insert(it, pair < long long, long long > (n, v));
		return v;
	}
	else return (*it).second;
}

int main()
{
	long long n;
	while(scanf("%lld", &n)==1)
	{
		M.clear();
		printf("%lld\n", func(n));
		for(it=M.begin();it!=M.end();it++)printf("n= %lld   v= %lld\n",(*it).first,(*it).second);
	}
	return 0;
}
