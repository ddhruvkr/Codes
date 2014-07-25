#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
      int i;
      char *s[]={
           "My name is Dhruv Kumar",
           "I am 19 years old"
           };
           char q[50];
           for(i=0;i<2;i++)
           {
                           strcpy(q,s[i]);
                           strrev(q);
                        printf("%s\n",q);
           }
           getch();
}
           
