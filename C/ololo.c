#include<stdio.h>

/*char c = 0;
int getInt() {
    int r = 0;
    while (!(c == '-' || (c >= '0' && c <= '9'))) c = getc_unlocked(stdin);
    bool minus = c == '-';
    if (minus) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return minus ? -r : r;
}*/

#define gc getchar_unlocked

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

long long int read_ll() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  long long int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int main()
{
    int n,i;
    n = read_int();
    long long int arr[n];
    for(i=0;i<n;i++)
		arr[i] = read_ll();
    long long int a,ans;
    a=arr[0];
    for(i=1;i<n;i++)
    {
        ans=a^arr[i];
        a=ans;
    }
    printf("%lld\n",ans);
    return 0;
}
