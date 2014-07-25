# include <cstdio>
# include <cstring>
# include <conio.h>
# include <list>
using namespace std;
int main()
{
	int N,count=0,s,n,d;
	list <int> x;
	list <int> y;
	list <int> z;
	list <int>::iterator i;
	list <int>::iterator j;
	list <int>::iterator k;
	y.push_back(0);
	x.push_back(0);
	scanf("%d" , &N);
	while(N--) {
		scanf("%d" , &d);
		x.push_back(d);
		scanf("%d" , &n);
		while(n--) {
			s=0;
			scanf("%d" , &d);
			y.push_back(d);
		}
	}
	z.push_back(0);
	j=y.begin();
	j++;
	for(;j!=y.end();j++) {
		s=0;
        for(i=x.begin();i!=x.end();i++)if(*j==*i)s=1;
        if(s!=1)
    		for(k=z.begin();k!=z.end();k++)if(*j==*k)s=1;
		if(s!=1){z.push_back(*j);count++;}
	}
	printf("%d\n" , count);
	getch();
	return 0;
}
