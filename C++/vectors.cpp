#include <stdio.h>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
// just do this, write vector<the type you want,
// in this case, integer> and the vector name
vector<int> v;
// try inserting 7 different integers, not ordered
v.push_back(3); v.push_back(1); v.push_back(2);
v.push_back(7); v.push_back(6); v.push_back(5);
v.push_back(4);
//erase(begin iterator, end iterator);
int count = v.size();
printf("%d\n" , count);
// to access the element, you need an iterator...
vector<int>::iterator i;
printf("Unsorted version\n");
// start with 'begin', end with 'end', advance with i++
for (i = v.begin(); i!= v.end(); i++)
printf("%d ",*i); // iterator's pointer hold the value
printf("\n");
sort(v.begin(),v.end()); // default sort, ascending
printf("Sorted version\n");
for (i = v.begin(); i!= v.end(); i++)
printf("%d ",*i); // iterator's pointer hold the value
printf("\n");
sort(v.rbegin(),v.rend()); // default sort, descending
printf("Sorted version\n");
for (i = v.begin(); i!= v.end(); i++)
printf("%d ",*i); // iterator's pointer hold the value
printf("\n");
printf("%d\n" , v.at(2));
int data[5] = { 5, 1, 4, 2, 3 };
vector<int> S(data, data+5);
reverse(data+1,data+3);
S.push_back(10);
printf("%d\n" , S[5]);
vector<int> v1(1000001);
for(int i = 0; i < 20; i++) {
v1[i] = i+1;
}
v1.resize(25);
for(int i = 20; i < 25; i++) {
v1[i] = i*2;
}
v1.clear();
v1.push_back(10);
printf("%d\n" , v1[0]);
getch();
return 0;
}
