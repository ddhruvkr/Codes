#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
    int i,l1,l2,e=0,d,j,r=0,s,max,min;
    char a[]="234894645775";
    char b[]="156";
    char c;
    //scanf("%s",a);
    //scanf("%s",b);
    l1=strlen(a);
    l2=strlen(b);

    scanf("%c",&c);
    char u[10000];
    char v[10000];
    switch(c)
    {
        case '+':
        if(l1>l2)r=1;
        if(r==1)
        {

            for(i=0;i<l1-l2;i++)v[i]='0';
            e=l1-l2;
            for(i=0;i<l2;i++){v[e]=b[i];e++;}
            v[e]='\0';
            j=l1-1;
            strcpy(u,a);
        }
        else
        {
            for(i=0;i<l2-l1;i++)u[i]='0';
            e=l2-l1;
            for(i=0;i<l1;i++){u[e]=a[i];e++;}
            u[e]='\0';
            j=l2-1;
            strcpy(v,b);
        }
        int x[2];
        x[0]=0;
        x[1]=0;
        d=j+2;
        char z[d];
        for(i=j;i>=0;i--)
        {
            s=x[1]+(int)u[i]+(int)v[i]-2*(int)'0';
            if(s<10){x[0]=s;x[1]=0;}
            else
            {
                x[0]=s%10;
                s=s/10;
                x[1]=s%10;
            }
            d--;
            z[d]=(char)(((int)'0')+x[0]);
            printf("%c\n",z[d]);
        }
        d--;
        z[d]=(char)(((int)'0')+x[1]);
        for(i=0;i<j+2;i++)printf("%c",z[i]);
        break;
        case '*':
        if(l1>l2){min=l2;max=l1;strcpy(u,a);strcpy(v,b);}
        else {min=l1;max=l2;strcpy(v,a);strcpy(u,b);}
        int y=-1,k;
        int uv[min][max+min+1];
        for(i=0;i<min;i++)
        for(j=0;j<=max+min;j++)
        uv[i][j]=0;
        for(i=min-1;i>=0;i--)
        {
            y++;
            k=max+min-y;
            for(j=max-1;j>=0;j--)
            {
                s=((int)v[i]-(int)('0'))*((int)u[j]-(int)('0'))+x[1];
                if(s<10){x[0]=s;x[1]=0;}
                else
                {
                   x[0]=s%10;
                   s=s/10;
                   x[1]=s%10;
                }
                uv[-i+min-1][k]=x[0];
                k--;
            }
            uv[i-min+1][k]=x[1];
            x[0]=0;
            x[1]=0;
        }
        for(i=0;i<min;i++)
        {
           for(j=0;j<=max+min;j++)
           printf("%d",uv[i][j]);
           printf("\n");
        }
        break;
        default:printf("Wrong Choice");
    }
    getch();
}
