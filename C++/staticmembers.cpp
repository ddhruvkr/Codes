#include <iostream>
#include <conio.h>
using namespace std;

class dummy {
	public:
		static int n;
		dummy() {n++;};
		~dummy() {n--;};
};

int dummy::n=0;

int main() {
	dummy a;
	dummy b[5];
	dummy *c = new dummy;
	cout << a.n << endl;
	delete c;
	cout << c->n << endl;
	getch();
	return 0;
}
