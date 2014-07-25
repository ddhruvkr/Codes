#include <iostream>
#include <string>
# include <conio.h>
using namespace std;
int main ()
{
	string s;
	int i;
  //std::string str="to be question";
  std::string str2="the ";
  std::string str3="or not to be";
  std::string::iterator it;
	//cin >> i;
	//cin >> s;
	//str.insert(i,s);
  // used in the same order as described above:
  //str.insert(6,str2);                 // to be (the )question
  //str.insert(6,str3,3,4);             // to be (not )the question
  //str.insert(10,"that is cool",8);    // to be not (that is )the question
  //str.insert(10,"to be ");            // to be not (to be )that is the question
  //str.insert(15,1,':');               // to be not to be(:) that is the question
  //it = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
  //str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
  //str.insert (it+2,str3.begin(),str3.begin()+3); // (or )

  //std::cout << str << '\n';
  char buffer[20];
  std::string str ("Test string...");
  i=str.length();
  std::size_t length = str.copy(buffer,1,7);
  buffer[length]='\0';
  std::cout << "buffer contains: " << buffer << '\n';
  getch();
  return 0;
}
