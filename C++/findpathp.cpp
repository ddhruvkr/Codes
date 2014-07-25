#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define get getchar_unlocked
#define LL long long
#define ULL unsigned long long
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(b))

int main()
{
    LL n,m,arr[50],i,k,x;queue<LL> Q;map<LL,LL> M;
    while(scanf("%lld %lld",&n,&m) != EOF){
                      for(i=1;i<=m;i++) {
                                        scanf("%lld",&arr[i]);
                                        if(arr[i] == 1 || n%arr[i] != 0) i--,m--;
                                        }
                      sort(arr+1,arr+1+m);
                      Q.push(1);
                      while(!Q.empty()){
                                        x=Q.front();
                                        Q.pop();
                                        for(i=1;i<=m;i++){
                                                          if(x*arr[i]<=n && M.find(x*arr[i])==M.end()){
                                                                          Q.push(x*arr[i]);
                                                                          M.insert(pair<LL,LL> (x*arr[i],x));
                                                                          }
                                                          }
                                        }
                      if(M.find(n) == M.end()){
                                   printf("-1\n");
                                   M.clear();
                                   continue;
                                   }
                      else {
                            k=0;
                            while(M[n] != 1){
                                            arr[k]=n;
                                            k++;
                                            n=M[n];
                                            //printf("%lld ",n);
                                            }
                            arr[k++]=n;
                            arr[k++]=M[n];
                            printf("%lld\n",k-1);
                            for(i=k-1;i>=0;i--) printf("%lld ",arr[i]);
                            printf("\n");
                            M.clear();
                            }
                      }

    return 0;
}

