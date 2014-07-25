# include <cstdio>
# include <set>
using namespace std;
int main ()
{
	int t, count = 0, j;
	scanf("%d",&t);
	while(t--)
	{
		count++;
		int n, r;
		scanf("%d%d",&n, &r);
		bool spy = true;
		set<int> s, c;
		for(j = 0; j < r; j++)
		{
			int r1, r2;
			scanf("%d%d",&r1,&r2);
			c.insert( r1 );
			s.insert( r2 );
		}
		for(j = 0; j < n; j++)
		{
			if( c.count( j ) > 0 && s.count( j ) > 0 )
			{
				spy = false;
				break;
			}
		}
		if( spy )
		printf("Scenario #%d: spying\n", count);
		else
		printf("Scenario #%d: spied\n", count);
	}
}
