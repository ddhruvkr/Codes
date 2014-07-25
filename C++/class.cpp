#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class CRectangle {
  public: int *x, y;
  public:
    void set_values (int,int);
    int area () {return ((*x) * y);}
};
void CRectangle::set_values (int a, int b) {
    x=new int;
    *x=a;
    y = b;
}
class yeah{
      public:
      string name;
      int no;
};

int main () {
    CRectangle rect, rectb;
    rect.set_values (3,4);
    rectb.set_values (5,6);
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    cout << (rectb.y+rect.y);
    vector <yeah> s;
    push_back("dhruv",19);
    return 0;
}
