# include <cstdio>
# include <map>
# include <vector>
using namespace std;
vector <long long> v;
vector <long long>::iterator it1;
long long happy(long long n)
{
	long long s=0,d;
	while(n!=0) {
		d=n%10;
		s=s+d*d;
		n=n/10;
	}
	return s;
}
int help(long long n)
{
	it1=v.begin();
	int q=-1;
	for(;it1!=v.end();it1++) {
	if((*it1)==n){q=0;break;}
	}
	return q;
}
int main()
{
    map < long long, long long > M;
	map < long long, long long > :: iterator it;
	int t;
	scanf("%d",&t);
	int q=-1,s;
	long long n,a;
	while(t--) {
		scanf("%lld",&n);
		s=0;
		v.clear();
		v.push_back(n);
		while(q!=0 && n!=1) {
			it=M.find(n);
			if(it==M.end()) {
				a=happy(n);
				s++;
				M.insert(it, pair < long long, long long > (n, a));
				n=a;
				q=help(n);
				if(q==-1)
				v.push_back(n);
			}
			else {
				s++;
				n=(*it).second;
				q=help(n);
				if(q!=-1)
				v.push_back(n);
			}
		}
		if(q==0)printf("-1\n");
		else printf("%d\n",s);
	}
	return 0;
}
