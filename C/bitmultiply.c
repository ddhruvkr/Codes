//How will you multiply two numbers using BITWISE operators
#include<stdio.h>
#include<conio.h>
main()
{
   int a,b,result;
   printf("nEnter the numbers to be multiplied :");
   scanf("%d%d",&a,&b);
   result=0;
   while(b != 0)               // Iterate the loop till b==0
   {
      if ((b&01)==1)               // Logical ANDing of the value of b with 01
      result=result+a;
      printf("%d   ",result); // Update the result with the new value of a.
      a<<=1;
      printf("%d   ",a);              // Left shifting the value contained in 'a' by 1.
      b>>=1;
      printf("%d   ",b);              // Right shifting the value contained in 'b' by 1.
      printf("\n");
   }
   printf("Result:%d",result);
   getch();
}
