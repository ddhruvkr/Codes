#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
    int l,n,i,j,d,w;
    scanf("%d",&n);
    char a[100][401];
    char s[100][403];
    for(i=0;i<n;i++)
    {
        d=1;w=0;
        s[i][0]='(';
        scanf("%s",&a[i][0]);
        l=strlen(a[i]);
        a[i][l]=')';
        a[i][l+1]='\0';
        for(j=0;j<=l;j++)
        {
            if(a[i][j]=='(')
            {s[i][d]=a[i][j];d++;}
            else if(a[i][j]>='a'&&a[i][j]<='z')
            printf("%c",a[i][j]);
            else if(a[i][j]=='^'){s[i][d]=a[i][j];d++;}
            else if((a[i][j]=='/'||a[i][j]=='*')&&s[i][d-1]!='^'){s[i][d]=a[i][j];d++;}
            else if((a[i][j]=='/'||a[i][j]=='*')&&s[i][d-1]=='^'){printf("%c",s[i][d-1]);s[i][d-1]=a[i][j];}
            else if((a[i][j]=='+'||a[i][j]=='-')&&s[i][d-1]!='^'&&s[i][d-1]!='/'&&s[i][d-1]!='*'){s[i][d]=a[i][j];d++;}
            else if((a[i][j]=='+'||a[i][j]=='-')&&(s[i][d-1]=='^'||s[i][d-1]=='/'||s[i][d-1]=='*')){printf("%c",s[i][d-1]);s[i][d-1]=a[i][j];}
            else if(a[i][j]==')')
            {
                w=d-1;
                while(s[i][w]!='(')
                      {
                          printf("%c",s[i][w]);
                          w--;
                      }
                      if(w==1&&j>=l-1)break;
                      d=w;
            }
        }
    }
    getch();
    return 0;
}






