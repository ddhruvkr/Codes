#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int i,b,l,j,e;
      char *s[]={
           "My name is Dhruv Kumar",
           "I am 19 years old"
           };
           char q[50];
           char w[15];
           for(i=0;i<2;i++)
           {
                           b=0;
                           strcpy(q,s[i]);
                           l=strlen(q);
                           for(j=0;j<=l;j++)
                           {
                                      if(q[j]==' '||q[j]=='\0')
                                      {
                                                 for(e=b-1;e>=0;e--)
                                                 printf("%c",w[e]);
                                                 printf(" ");
                                                 char w[15];
                                                 b=0;
                                      }
                                      else 
                                      {
                                           w[b]=q[j];
                                           b++;
                                      } 
                                      }
                           printf("\n");
                             
           }
           getch();
}
