#include<stdio.h>
#include<conio.h>
int main()
{
  int num=0,a,b,a1,a2,d=0,e,x;
  
  scanf("%d\n",&num);
  for(a=1;a<=num;a++)
  {
                    scanf("%d%d",&a1,&a2);
                    printf("\n"); 
                    for(b=a1;b<=a2;b++)
                    {
                                      for(e=1;e<=b;e++)
                                      {
                                                         if(b%e==0)
                                                         d++;
                                      }
                                                         if(d==2)
                                                         printf("%d\n",b);
                                                         d=0;
                    }
  }
  getch();
  return 0;
  }
  
    
