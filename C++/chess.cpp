#include <stdio.h>
#define max(a,b) (((a)<(b))?(b):(a))
#define min(a,b) (((a)<(b))?(a):(a))
int abs(int a)
{
    if(a<0) return -1*a;
    return a;
}
int main()
{
    int x1,y1,x2,y2,z1,z2;
    int dist[64][64];
    for(x1=0;x1<64;x1++)
    for(y1=0;y1<64;y1++)
                       dist[x1][y1]=1000000;
    for(x1=0;x1<8;x1++)
    for(y1=0;y1<8;y1++)
    for(x2=0;x2<8;x2++)
    for(y2=0;y2<8;y2++){
    if( (abs(x2-x1) == 2 && abs(y2-y1) == 1) || (abs(x2-x1) == 1 && abs(y2-y1) == 2) )
                   dist[x1*8+y1][x2*8+y2]=x1*x2+y1*y2;
                   if(x1 == x2 && y1==y2) dist[x1*8+y1][x2*8+y2]=0;}
    for(z1=0;z1<8;z1++)
    for(z2=0;z2<8;z2++)
    for(x1=0;x1<8;x1++)
    for(y1=0;y1<8;y1++)
    for(x2=0;x2<8;x2++)
    for(y2=0;y2<8;y2++)
                       if(dist[x1*8+y1][x2*8+y2] > dist[x1*8+y1][z1*8+z2]+dist[z1*8+z2][x2*8+y2])
                                     dist[x1*8+y1][x2*8+y2]=dist[x1*8+y1][z1*8+z2]+dist[z1*8+z2][x2*8+y2];
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)!=EOF)
    printf("%d\n",dist[x1*8+y1][x2*8+y2]>100000?-1:dist[x1*8+y1][x2*8+y2]);

    return 0;
}
