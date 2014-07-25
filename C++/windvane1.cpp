#include <stdio.h>
#include <iostream>

using namespace std;

int m, n, ar[1001][1001];
int i, j, clk, t, ad, x1, x2, ya, yb;
char ch[1001], d;

int main()
{
        cin>>m>>n;

        for (i = 1; i <= m; ++i) {
                cin>>ch;

                for (j = 1; j <= n; ++j) {
                        d = ch[j - 1];
                        switch (d) {
                                case 'N':{
                                        ar[i][j] = 0;
                                        break;
                                }
                                case 'E':{
                                        ar[i][j] = 1;
                                        break;
                                }
                                case 'S':{
                                        ar[i][j] = 2;
                                        break;
                                }
                                case 'W':{
                                        ar[i][j] = 3;
break;
                                }
                        }

                }
        }

        cin>>t;

        while (t--) {
                cin>>d;

                if (d == 'C') {

                        cin>>x1>>ya>>x2>>yb>>clk;

                        if (clk) {
                                ad = 3;
                        } else {
                                ad = 1;
                        }

                        for (i = x1; i <= x2; ++i) {
                                for (j = ya; j <= yb; ++j) {
                                        ar[i][j] += ad;
                                        ar[i][j] %= 4;
                                }
                        }

                } else {
                        cin>>x1>>ya;

                        switch (ar[x1][ya]) {
                                case 0:{
                                        printf("%s\n", "N");
                                        break;
                                }
                            case 1:{
                                        printf("%s\n", "E");
                                        break;
                                }
                                case 2:{
                                        printf("%s\n", "S");
                                        break;
                                }
                                case 3:{
                                        printf("%s\n", "W");
                                        break;
                                }
                        }
                }
        }
        return 0;
}
