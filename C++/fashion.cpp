/*# include <cstdio>
# include <list>
# include <conio.h>
using namespace std;
int main()
{
	int t,n,i,j,s;
	list <int> m;
	list <int> w;
	list <int>::iterator i1;
	list <int>::iterator j1;
	scanf("%d" , &t);
	m.push_back(0);
	w.push_back(0);
	while(t--) {
		s=0;
		scanf("%d" , &n);
		for(i=0;i<n;i++){scanf("%d" , &j);m.push_back(j);}
		for(i=0;i<n;i++){scanf("%d" , &j);w.push_back(j);}
		m.sort();
		w.sort();
		i1 = m.begin();i1++;
		j1 = w.begin();j1++;
		for(i=0;i<n;i++,i1++,j1++) {
			s = s+((*i1)*(*j1));
			//m.erase(i1);
			//w.erase(j1);
		}
		printf("%d\n" , s);
		i1 = m.begin();i1++;
		j1 = w.begin();j1++;
		for(i=0;i<n;i1++,j1++,i++){m.erase(i1);w.erase(j1);}
		
	}
	getch();
	return 0;
}*/
#include<iostream>
#include<algorithm>
#include<conio.h>
#include<cstdio>
using namespace std;

int main()
{
    int test, N, M, ans, i;
    int men[1001], women[1001];

    scanf("%d", &test);
    while (test--) {
 ans = 0;
 scanf("%d", &N);
 for (i = 0; i < N; i++)
     scanf("%d", &men[i]);
 for (i = 0; i < N; i++)
     scanf("%d", &women[i]);
 sort(men, men + N);
 sort(women, women + N);
 for (i = 0; i < N; i++)
     ans += men[i] * women[i];
 printf("%d\n", ans);
    }
    getch();
    return 0;
}
