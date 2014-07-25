#include<cstdio>
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
#define Lim 99998954
vector<bool> b((Lim>>1)+100);


void prime()
    {
        for(int i=3;i<=10000;i+=2) if(!b[(i-3)>>1]) for(int j=i*i;j<Lim;j+=2*i)   b[(j-3)>>1]=1;
        /*p[0]=2;
        int cnt=1;
        for(int i=0;2*i<Lim;i++) if(!b[i]) p[cnt++]=2*i+3;*/
        /*for(int i=0;i<10;i++) cout<<p[i]<<" ";
        cout<<endl;
        for(int i=cnt-10;i<cnt;i++) cout<<p[i]<<" ";
        cout<<cnt<<endl;*/

    }


int main()
    {
        prime();
        int k,q,i;
        /*for(scanf("%d",&q);q>0;q--) scanf("%d",&k) , printf("%d\n",p[k-1]);*/
        k=1;
        printf("2\n");
        for(i=0;2*i<Lim;i++)
        {
                            if(!b[i])
                            {
                                     k++;
                                     if(k%100==1)
                                     printf("%d\n",(2*i+3));
                            }

       }
getch();
       return 0;
    }
