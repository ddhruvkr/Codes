#include <stdio.h>
#include <conio.h>
main()
{
    int v=0,x=1,i=0,j=0,b=0,n=0,f=1;
    scanf("%d",&n);
    int a[n][n];
    b=n;
    while(x<=n*n)
    {
    for(j=v;j<b;j++)a[i][j]=x++;j--;
    for(i=v+1;i<b;i++)a[i][j]=x++;i--;
    for(j=i-1;j>=v;j--)a[i][j]=x++;j++;
    for(i=b-2;i>v;i--)a[i][j]=x++;i++;
    v++; b--;
    }
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n;j++)printf("%d\t",a[i][j]);
                    printf("\n");
    }
    getch();
}
    
    
    
