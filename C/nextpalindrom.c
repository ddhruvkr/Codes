#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int n,i,j,l,z,r;
      char s[1000000];
      char a[1000000];
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
                      scanf("%s",&s);
                      l=strlen(s);
                      if(l%2!=0)
                      {
                                int q=-1;
                                for(j=0;j<l;j++)
                                {
                                                if(j<l/2){q++;a[j]=s[q];}
                                                else if(j>l/2){q--;a[j]=s[q];}
                                                else
                                                {q++;a[j]=s[q];}               
                                }
                                if(strcmp(a,s)<0)
                                {
                                                 if(s[l/2]=='9')
                                                 {
                                                                for(r=(l/2);r>=0;r--)
                                                                {
                                                                                     if(s[r]=='9')
                                                                                     s[r]='0';
                                                                                     else
                                                                                     {s[r]++;break;}
                                                                }
                                                                q=-1;
                                                                for(j=0;j<l;j++)
                                                                {
                                                                                if(j<l/2){q++;a[j]=s[q];}
                                                                                else if(j>l/2){q--;a[j]=s[q];}
                                                                                else
                                                                                {q++;a[j]=s[q];}
                                                                }
                                
                                                 }
                                                 else
                                                 {       
                                                 s[l/2]++;
                                                 q=-1;
                                                 for(j=0;j<l;j++)
                                                 {
                                                                 if(j<l/2){q++;a[j]=s[q];}
                                                                 else
                                                                 if(j>l/2){q--;a[j]=s[q];}
                                                                 else
                                                                 {q++;a[j]=s[q];}
                                                 }
                                                 }   
                                }
                                printf("%s",a);
                                printf("\n");
                      }
                      else
                      {
                                int q=-1;
                                for(j=0;j<l;j++)
                                {
                                                if(j<l/2){q++;a[j]=s[q];}
                                                else if(j>l/2){q--;a[j]=s[q];}
                                                else if(j=l/2){a[j]=s[q];}
                                }
                                if(strcmp(a,s)<0)
                                {
                                                 z=(int)s[(l/2)-1];
                                                 z=z+1;
                                                 s[(l/2)-1]=(char)z;
                                                 q=-1;
                                                 for(j=0;j<l;j++)
                                                 {
                                                                 if(j<l/2){q++;a[j]=s[q];}
                                                                 else
                                                                 if(j>l/2){q--;a[j]=s[q];}
                                                                 else if(j=l/2){a[j]=s[q];}
                                                 }     
                                }
                                printf("%s",a);
                                printf("\n");
                      }
      }
      getch();
}
                                      
