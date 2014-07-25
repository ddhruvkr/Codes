#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int i,j,t=0;
      char *s[]=
      {
     "Dhruv",
     "Prakhar",
     "Anant"
      };
      char *p;
      for(i=t;i<2;i++)
      {
                      for(j=t+1;j<3;j++)
                      {
                                        if(strcmp(s[i],s[j])>0)
                                        {
                                                     p=s[i];
                                                     s[i]=s[j];
                                                     s[j]=p;
                                        }
                      }
                      t++;
      }
      for(i=0;i<3;i++)
      printf("%s\n",s[i]);
      getch();
}                
                                         
          
