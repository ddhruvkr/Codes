#include <cstdio>
#include <map>

using namespace std;

int main() {
	int t, a, b, c, n, k, i, ans;
	scanf("%d", &t);
	//t = read_int();
	while(t--) {
        //n = read_int();
        //k = read_int();
		scanf("%d%d", &n, &k);
		multimap<int,int> m[100000];
		map <int, int> um;
		map <int, int> ::iterator ti;
		int x = 0;
		for(i = 1; i <= n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			//a = read_int();
			//b = read_int();
			//c/ = read_int();
			ti = um.find(c);
			if(ti == um.end()) {
                um.insert(ti, pair < int, int > (c, x));
                m[x].insert(pair<int, int>(a,b));
                x++;
			}
			else {
				c = (*ti).second;
				m[c].insert(pair<int, int>(a,b));
			}
		}
		ans = 0;
		for(i = 0; i < x; i++) {
            multimap<int,int>::iterator it = m[i].begin();
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
		printf("%d\n", ans);
		//writeInt(ans);
	}
	return 0;
}
