#include <stdio.h>      /* printf */
#include <time.h>
#include <conio.h>       /* time_t, struct tm, difftime, time, mktime */

int main ()
{
  time_t timer;
  struct tm y2k;
  double seconds;
  int m = 2838, a = 9383, c = 34333;
  int x = 283832 * 283831;

  y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
  y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

  time(&timer);  /* get current time; same as: timer = time(NULL)  */

  seconds = difftime(timer,mktime(&y2k));
  int n = (int)seconds;
	n %= m;
	
  //printf ("%.f seconds since January 1, 2000 in the current timezone %d", seconds, x);
  while(1) {
		getch();
        printf("%d\n", n);
		n = (((a%m)*(n%m))%m + c%m)%m;
  }
getch();
  return 0;
}
