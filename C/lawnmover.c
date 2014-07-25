# include <stdio.h>
int main()
{
	int nx,ny,i,l1,j,i1,j1,e=0,q,l;
	float w,z;
	float a[1000],b[1000];
	int arr[76][101];
	scanf("%d%d%f",&nx,&ny,&w);
	while(nx!=0 && ny!=0 && w!=0.0) {
		e=0;
		for(i=0;i<=75;i++)for(j=0;j<=100;j++)arr[i][j]=0;
		for(i=0;i<nx;i++)scanf("%f",&a[i]);
		for(i=0;i<ny;i++)scanf("%f",&b[i]);
		q=0;
		w=w/2;
		for(i=0;i<nx;i++) {
			z=a[i];
			if((int)z<=(int)w) {
				l=(int)(z+w);
				for(i1=1;i1<=l;i1++)
				for(j1=1;j1<=100;j1++) {
					if(arr[i1][j1]!=1){q++;arr[i1][j1]=1;}
				}
                //printf("1 %d %f\n",q,z);
			}
			else if((int)z>=75-(int)w) {
                l=(int)(z-w);
				for(i1=l;i1<=75;i1++)
				for(j1=1;j1<=100;j1++) {
                    if(arr[i1][j1]!=1){q++;arr[i1][j1]=1;}
				}
				//printf("2 %d %f\n",q,z);
			}
			else {
                l=(int)(z+w);
                l1=(int)(z-w);
				for(i1=l1;i1<=l;i1++)
				for(j1=1;j1<=100;j1++) {
                    if(arr[i1][j1]!=1){q++;arr[i1][j1]=1;}
				}
                //printf("3 %d %f\n",q,z);
			}
		}
		if(q==7500) {
			q=0;e++;
			for(i=0;i<ny;i++) {
				z=b[i];
			//printf("%f\n",z);
				if((int)z<=(int)w) {
					l=(int)(z+w);
					for(i1=1;i1<=l;i1++)
					for(j1=1;j1<=75;j1++) {
                    	if(arr[j1][i1]!=2){q++;arr[j1][i1]=2;}
					}
                //printf("4 %d %f\n",q,z);
				}
				else if((int)z>=100-(int)w) {
                	l=(int)(z-w);
					for(i1=l;i1<=100;i1++)
					for(j1=1;j1<=75;j1++) {
                   		if(arr[j1][i1]!=2){q++;arr[j1][i1]=2;}
					}
                //printf("5 %d %f\n",q,z);
				}
				else {
					l=(int)(z+w);
                	l1=(int)(z-w);
                //printf("yeah");
                //if((int)z==70)print("yeah\n");
					for(i1=l1;i1<=l;i1++)
					for(j1=1;j1<=75;j1++) {
                    	if(arr[j1][i1]!=2){q++;arr[j1][i1]=2;}
					}
                //printf("6 %d %f\n",q,z);
				}
			}
 		}
		if(q==7500 && e==1)printf("YES\n");
		else printf("NO\n");
        scanf("%d%d%f",&nx,&ny,&w);
	}
	return 0;
}


#include <algorithm>
#include <cstdio>
using namespace std;
const int NN = 1048;
double x[NN], y[NN];
int main(void){
    int nx, ny; double w;
    while(scanf("%d %d %lf", &nx, &ny, &w) == 3 && (nx || ny)){
        for(int i = 0; i < nx; ++i) scanf("%lf", &x[i]);
        for(int i = 0; i < ny; ++i) scanf("%lf", &y[i]);
        sort(x, x + nx);
        sort(y, y + ny);
        w /= 2.0;
        if(x[0] - w > 0 || y[0] - w > 0 || x[nx - 1] + w < 75 || y[ny - 1] + w < 100)
            puts("NO");
        else {
            bool ok = 1;
            double r = 0;
            for(int i = 0; ok && i < nx; ++i){
                ok &= !(x[i] - w > r);
                r = x[i] + w;
            }
            r = 0;
            for(int i = 0; ok && i < ny; ++i){
                ok &= !(y[i] - w > r);
                r = y[i] + w;
            }
            if(ok) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
