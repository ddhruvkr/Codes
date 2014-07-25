#include <stdio.h>
#include <conio.h>
main()
{
      int i,t,s=0,e,z;
      char a[19];
      gets(a);
      i=17;
      while(i>=0)
      {
                 t=2;
                 if(t==2)
                 {
                      e=((int)(a[i]))*2;
                      if(e>10)e=e-9;
                      s=s+e;
                      i=i-t;
                 }
                 else if(t==3)
                 {
                      e=((int)(a[i])*2);
                      if(e>10)e=e-9;
                      s=s+e;
                      i=i-t;
                 }
                 t=3;
      }
      i=18;
      while(i>=0)
      {
                 if(a[i]!=' ')
                 z=z+(int)(a[i]);
                 i--;
      }
      if((z+s)%10==0)printf("Valid");
      else printf("Not Valid");
      getch();
}
                 
                         
