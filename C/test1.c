#include <stdio.h>
#include <conio.h>
char a[][10]={"Violet","Indigo","Blue","Green","Yellow","Orange","Red"};
int main()
{
    int color;
    scanf("%d",&color);
    int i,b,c;
    for(i=7;i>=0;i--)
    {
         b= 1<<i;
         c= color&b;
         c==0?printf("0"):printf("1");
    }
    printf("\n");
    getch();
    return 0;
}

    
