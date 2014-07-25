#include <cstdio>
#include <set>
#include <map>

using namespace std;

#define gc getchar_unlocked
#define pc putchar_unlocked

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

inline void writeInt (long long n)
{
    long long N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;}
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
    pc('\n');
    return ;
}

struct comp
{
bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
{
  return p1.second <= p2.second;
}
};

int main() {
	int t, a, b, c, n, k, i, ans;
	//scanf("%d", &t);
	t = read_int();
	while(t--) {
        n = read_int();
        k = read_int();
		//scanf("%d%d", &n, &k);
		set<pair<int,int>,comp> m[100000];
		map <int, int> um;
		map <int, int> ::iterator ti;
		int x = 0;
		for(i = 1; i <= n; i++) {
			//scanf("%d%d%d", &a, &b, &c);
			a = read_int();
			b = read_int();
			c = read_int();
			ti = um.find(c);
			if(ti == um.end()) {
                um.insert(ti, pair < int, int > (c, x));
                m[x].insert(make_pair(a,b));
                x++;
			}
			else {
				c = (*ti).second;
				m[c].insert(make_pair(a,b));
			}
		}
		ans = 0;
		for(i = 0; i < x; i++) {
            multiset<pair<int,int>,comp>::iterator it = m[i].begin();
            //for(; it != m[i].end(); it++)printf("%d %d\n", it->first, it->second);
  			int end_time = it->second;
  			int activities = 1;
  			it++;
  			for(; it != m[i].end(); it++)
    		if(it->first >= end_time)
    		{
     			end_time = it->second;
     			activities++;
    		}
    		ans += activities;
		}
		//printf("%d\n", ans);
		writeInt(ans);
	}
	return 0;
}
