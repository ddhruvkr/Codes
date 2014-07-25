# include <cstdio>
# include <sstream>
# include <conio.h>
# include <vector>
# include <set>
# include <algorithm>
# define all(c)
# define (c).begin()
# define (c).end()
using namespace std;
void func(string& t) {
	istringstream is(t);
	vector <int> v;
	vector <int>:: iterator it;
	int tmp;
	while(is>>tmp) {
		v.push_back(tmp);
	}
	set <int> s(all(v));
	vector <int> v1(all(s));
	it=v1.begin();
	for(;it!=v1.end();it++)printf("%d ",(*it));
}
int main()
{
	string s = "1210129";
	func(s);
	getch();
	return 0;
}
