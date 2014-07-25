# include <cstdio>
# include <conio.h>
# include <list>
# include <algorithm>
using namespace std;
int a[1000000];
/*void print()
{
	list <int>::iterator i;
	for(i=l.begin();i!=l.end();i++)
	printf("%d  " , *i);
	printf("\n");
}*/

int main()
{
	int t,count,q,z,j,v=0,br=0;
	scanf("%d",&t);
	for(j=0;j<t;j++)scanf("%d",&a[j]);
	sort(a,a+t);
	list <int> l;
	list <int>::iterator i;
	list <int> l1;
	list <int>::iterator i1;
	list <int>::iterator p;
	l.push_back(a[0]);
	l1.push_back(1);
	z=1;count=1;
	while(z<t) {
		//printf("%d\n",z);
		//printf("%d\n",count);
		if(v!=1) {
		i=l.begin();
		i1=l1.begin();
	    }
		v=0;
		//printf("%d\n",*i1);
		if(*(i1)==4){
			if(l.size()==1)br=1;
			i=l.erase(i);
			i1=l1.erase(i1);
			if(br==1 && z!=t-1) {
                l.push_back(a[++z]);
				l1.push_back(1);
				count++;
			}
			else if(br==1 && z==t-1){count++;z++;
			}
			br=0;
		}
		else if((a[z]-*(i))==30){
			*(i)+=30;
			(*i1)++;
			z++;
		}
		else if((a[z]-*(i))>30){
			//printf("%d\n",l.size());
			//print();
			if(l.size()==1)br=1;
			i=l.erase(i);
			//printf("dhruv %d\n",br);
			i1=l1.erase(i1);
			if(br==1 && z!=t-1) {
                l.push_back(a[++z]);
				l1.push_back(1);
				count++;
			}
			else if(br==1 && z==t-1){count++;z++;
			}
			
			br=0;
		}
		else if((a[z]-*(i))<30){
			p=i;
			p++;
			if(p==l.end())
			{
				l.push_back(a[z]);
				l1.push_back(1);
				z++;
				count++;
			}
			else {
				i++;
				i1++;
				v=1;
			}
		}
	}
	printf("%d\n",count);
	getch();
	return 0;
}
