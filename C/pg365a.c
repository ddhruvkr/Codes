#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int i,b,l,j,z,e;
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
                                                 if(strcmp(w,"Dhruv")==0)printf("%s","Prakhar");
                                                 else 
                                                 for(z=0;z<b;z++)printf("%c",w[z]);
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
