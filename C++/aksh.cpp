#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <conio.h>
#include <sstream>
using namespace std;
class stud{
      public:
      string name;
      int no;
      void setdetails(string a,int x){
      name=a;
      no=x;
           }
};
int main()
{
vector <stud> s;
stud p0;
p0.setdetails("akshenndra",78);
stud p1;
p1.setdetails("bucky",79);
s.push_back(p0);
s.push_back(p1);

cout << s[0].name << "\n" << s[1].name << endl;
  int i;
  char buffer [33];
  printf ("Enter a number: ");
  scanf ("%d",&i);
  itoa (i,buffer,10);
  printf ("decimal: %s\n",buffer);
  itoa (i,buffer,16);
  printf ("hexadecimal: %s\n",buffer);
  itoa (i,buffer,2);
  printf ("binary: %s\n",buffer);

int Number = 123;       // number to be converted to a string

string Result;          // string which will contain the result

ostringstream convert;   // stream used for the conversion

convert << Number;      // insert the textual representation of 'Number' in the characters in the stream

Result = convert.str();
cout << Result;



getch();
return 0;

}
