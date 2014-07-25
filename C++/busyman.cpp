# include <cstdio>
# include <list>
# include <conio.h>
using namespace std;
list <int> l;
int main()
{
	list <int>::iterator p;
    list <int>::iterator r;
	int t;
	long int n , z , s , i , j , x ,start , end;
	scanf("%d" , &t);
	for(i=0;i<t;i++) {
		scanf("%ld" , &n);
		scanf("%ld %ld" , &start , &end);
		l.push_back(start);
		l.push_back(end);
		s = 1;
		for(j=1;j<n;j++) {
			x = 0;
			scanf("%ld %ld" , &start , &end);
			p = l.begin();
			p++;
			r = p;
			p--;
			if(end<=(*p)) {
				s++;
				l.push_back(start);
				l.push_back(end);
				l.sort();
			}
			else if(s == 1 && start>=*r) {
				s++;
                l.push_back(start);
				l.push_back(end);
				l.sort();
			}
			else if(s>1) {
				p = l.begin();
				p++;
				p++;
				r = p;
				p--;
				for(z=1;z<(l.size()-2);z=z+3) {
					if(start>=*p && end<=*r) {
						s++;
						x = 1;
						l.push_back(start);
						l.push_back(end);
						l.sort();
					}
				}
				if(x == 0) {
					r = l.end();
					r--;
					if(start>=(*(r))) {
						s++;
                    	l.push_back(start);
						l.push_back(end);
						l.sort();
					}
				}
			}
		}
		while (!l.empty())
    	l.pop_back();
        printf("%d\n" , s);
	}
	getch();
	return 0;
}
