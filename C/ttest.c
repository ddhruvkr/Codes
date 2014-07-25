#include <stdio.h>
#include <conio.h>
void qsort(int *,int,int);
int partition(int *,int,int);
main()
{
    int a[]={2,8,7,1,3,5,6,4};
    int x,c=0,b=7,z,i=-1,j;
    qsort(&a[0],c,b);
    void qsort(int *u,int p,int r)
    {
        int w;
        if(p<r)
        {
            w=partition(u,p,r);
            qsort(u,p,z-1);
            qsort(u,z+1,r);
        }
    }
    for(i=0;i<8;i++)
    printf("%d,",a[i]);
    int partition(int *b,int p,int r)
    {
        int l[7];
        for(i=0;i<7;i++)
        {
            l[i]=*b;
            b++;
        }
        int t;
        x=l[r];
        i=p-1;
        for(j=p;j<r;j++)
        {
            if(l[j]<=x)
            {
                i++;
                t=l[i];
                l[i]=l[j];
                l[j]=t;
            }
        }
        t=l[i+1];
        l[i+1]=l[r];
        l[r]=t;
        return (i+1);
    }
}
