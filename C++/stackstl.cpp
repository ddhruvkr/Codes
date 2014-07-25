#include <stdio.h>
#include <conio.h>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	s.push(3);
	s.push(5);
	s.push(1);
	s.push(2);
	s.push(4);
	while(!s.empty()) {
		printf("%d " , s.top());
		s.pop();
	}
	//s.pop();
	getch();
	return 0;
}
