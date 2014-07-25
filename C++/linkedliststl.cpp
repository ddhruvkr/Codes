#include <stdio.h>
#include <conio.h>
#include <list>
//#include <algorithm>;
using namespace std;
list <int> l;
list <int>::iterator i;

void print()
{
	for(i=l.begin();i!=l.end();i++)
	printf("%d  " , *i);
	printf("\n");
}
int main()
{
	l.push_back(3);
	l.push_back(1);
	l.push_back(2);
	l.push_back(7);
	l.push_back(6);
	l.push_back(5);
	l.push_back(4);
	l.push_back(7);
	printf("%d\n",l.size());
	print();
	l.sort();
	print();
	//l.remove(1);
	//print();
	//l.unique();
	//print();
	//i=l.begin();
	//i++;
	//l.insert(i,2,10);
	//print();
	i = l.begin();
	//l.remove(*(i+1));
	print();

	getch();
	return 0;
}
