#include<stdio.h>
#include<conio.h>
int add(int,int,int);
main()
{
  int a,b,c,sum;
  printf("enter 3 nos a,b,c");
  scanf("%d%d%d",&a,&b,&c);
  add(a,b,c);
 printf("%d",sum);
 getch();
}
int add(int a,int b,int c)
  {
       int sum=0;
    sum=sum+a+b+c;
    return(sum);
}

