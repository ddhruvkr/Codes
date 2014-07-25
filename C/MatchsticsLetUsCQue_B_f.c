#include<stdio.h>
main()
{
      int n,a=5;
      printf("Lets play a game. We have 21 match sticks. At a time u as well as computer can choose 1,2,3 or 4 sticks. Who so ever is left with the last stick to choose is the loser.");
      while(a<=20)
      {
           printf("\n\nEnter ur choice: ");
           scanf("%d",&n);
           printf("\nno. entered by computer: %d",(5-n));
           printf("\nTotal becomes: %d",a);
           a=a+5;
      }
      printf("\n\n You are left with only one choise i.e. 21 so you lose\n");
      system("pause");
}           
