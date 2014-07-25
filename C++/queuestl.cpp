#include <stdio.h>
#include <conio.h>
#include <queue>
// use this to avoid specifying "std::" everywhere
using namespace std;
int main() {
// just do this, write queue<the type you want,
// in this case, integer> and the queue name
queue<int> q;
// try inserting 7 different integers, not ordered
q.push(3); q.push(1); q.push(2);
q.push(7); q.push(6); q.push(5);
q.push(4);
// the item that is inserted first will come out first
// First In First Out (FIFO) order...
while (!q.empty()) {
// notice that this is not "top()" !!!
printf("front = %d ",q.front());
//printf("rear = %d \n" , q.rear());
q.pop();
}
q.pop();
q.pop();//gives no error even if underflow
printf("\n");
getch();
return 0;
}
