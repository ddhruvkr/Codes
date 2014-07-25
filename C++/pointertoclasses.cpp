#include <iostream>
using namespace std;

class Rectangle {
	int height, width;
	public:
		void setvalue(int, int);
		int area(void) {return (width*height);
		}
};

void Rectangle::setvalue(int a, int b) {
	width=a;
	height=b;
}

int main() {
	Rectangle a, *b, *c;
	Rectangle *d = new Rectangle[2];
	b=new Rectangle;
	c=&a;
	a.setvalue(3,4);
	b->setvalue(4,5);
	d->setvalue(5,6);
	d[1].setvalue(6,7);
	cout << "a area= " << a.area() << endl;
	cout << "*b area= " << b->area() << endl;
	cout << "*c area= " << c->area() << endl;
	cout << "*d[0] area= " << d[0].area() << endl;
	cout << "*d[1] area= " << d[1].area() << endl;
	return 0;
}
