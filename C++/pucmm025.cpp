# include <cstdio>
# include <cstring>
using namespace std;
int main() {
	char s[1024], b[10];
	int c[10];
	int count, i, l, j, sum, d;
	while(gets(s)) {
		count = 0;
		sum = 0;
		l = strlen(s);
		for(i = 1; i < 10; i++) {
			b[i] = 'n';
			c[i] = 0;
		}
		for(i = 0; i < l; i++) {
			d = s[i] - '0';
			c[d]++;
		}
		for(i = 1; i < 10; i++) {
			if(b[i] == 'n' && c[i] > 0) {
				sum = 0;
				for(j = 0; j < l; j++) {
					sum = ((sum * 10) + (s[j] - '0')) % i;
				}
				if(sum == 0) {
				count = count + c[i];
				b[i] = 'y';
				}
			}
		}
		printf("%d\n" , count);
	}
	return 0;
}




/*



#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

//#define DEBUG(x) cout << #x << ": " << x << endl
//#define sz(a) int((a).size())
//#define all(x) (x).begin(),(x).end()
//#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

char s[1024];
bool divide[10];

int main(int argc, char *argv[]) {
   int n, res;
   while(gets(s)) {
      n = strlen(s);
      memset(divide,false,sizeof(divide));
      for(int i = 2; i <= 9; ++i) {
         int rem = 0;
         for(int j = 0; j < n; ++j)
            rem = (rem*10 + (s[j]-'0')) % i;
         if(!rem) divide[i] = true;
      }
      res = 0;
      for(int i = 0; i < n; ++i) {
         if((s[i]-'0') == 1) res++;
         else if(divide[(s[i]-'0')]) res++;
      }
      printf("%d\n",res);
   }
   return 0;
}
*/
