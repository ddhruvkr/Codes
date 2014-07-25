#include "stdio.h"
#include "limits.h"
#include <conio.h>
int sign(int number) {
  return (unsigned) number / (unsigned) INT_MIN;
}
int main() {
	//int a = 19;
	//int b = (unsigned) a;
	int b = (unsigned) -5;
	printf("%d\n", -5/INT_MIN);
	int a;
  scanf("%d%d", &a, &b);
  int dif = a - b;
  int sb1 = sign(dif);
  printf("%d\n", sb1);
  int sb2 = sign(dif - 1) - sb1;
  printf("%d\n", sb2);
  int ptr = 2 * sb2 + sb1;
  printf("%d\n", ptr);
  char *messages[3] = {
    "%d is greater than %d",
    "%d is less than %d",
    "%d is equal to %d" };
  printf(messages[ptr], a, b);
  getch();
}
