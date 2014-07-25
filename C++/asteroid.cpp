#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
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

int arr[1002][1002], maxwid[1002][1002], area[1002][1002], dp[1002][1002];

int main()
{
    int n, m, i, j, k, h, w, l;
    //scanf("%d%d", &n, &m);
    n = read_int();
    m = read_int();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            //scanf("%d", &inp[i][j]);
            arr[i][j] = read_int();
            arr[i][j] = arr[i][j] ^ 1;
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr[i][j]) {
               arr[i][j] = arr[i-1][j] + 1;
            } else {
               arr[i][j] = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        stack <int> st;
        for (j = 0; j <= m; j++) {
            h = (j == m) ? -1 : arr[i][j];
            while (!st.empty()) {
                  if (arr[i][st.top()] >= h) {
                     k = st.top();
                     st.pop();
                     if (st.empty()) {
                        w = j;
                     } else {
                        w = j - st.top() - 1;
                     }
                     if (maxwid[i][arr[i][k]] < w) {
                        maxwid[i][arr[i][k]] = w;
                     }
                  } else {
                     break;
                  }
            }
            st.push(j);
        }
    }

    for (i = 0; i < n; i++) {
        k = 0;
        for (j = i+1; j >= 0; j--) {
            if (k < maxwid[i][j]) {
               k = maxwid[i][j];
            }
            area[i][j] = k * j;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= (i+1); j++) {
            dp[i][j] = max(area[i][j], max(dp[i][j-1], dp[i-1][j-1]));
        }
    }

    int q;
    //scanf("%d", &q);
	q = read_int();
    while (q--) {
          //scanf("%d%d", &i, &j);
          i = read_int();
          j = read_int();
          i--;
          j--;
          k = j - i + 1;
          printf("%d\n", dp[j][k]);
    }
    return 0;
}
