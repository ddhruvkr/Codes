# include <cstdio>
# include <map>
using namespace std;
int main() {
	int t, n, r, br, count = 0, c, i;
	multimap <int , int> m;
	scanf("%d", &t);
	while(t--) {
		br = 0;
		count++;
		scanf("%d%d", &n, &r);
		for(int j = 0; j < r; j++) {
			scanf("%d%d", &i, &c);
			pair<multimap<int,int> :: iterator, multimap<int, int> :: iterator> p;
			if(br != 1) {

				p = m.equal_range(i);
				for (multimap<int, int> :: iterator x = p.first; x != p.second; x++) {
					if(x->second == c){
						br = 1;
						break;
					}
				}
				if(br != 1)m.insert(pair<int, int>(i, c));
			}
		}
		m.clear();
		if(br != 1)printf("Scenario #%d: possible\n", count);
		else printf("Scenario #%d: impossible\n", count);
	}
	return 0;
}
