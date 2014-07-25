//The 8 queens problem is a classic problem using the chess board. This problem is to place 8 queens on the chess board so that they do not attack each other horizontally, vertically or diagonally. It turns out that there are 12 essentially distinct solutions to this problem.
//Suppose we have an array t[8] which keeps track of which column is occupied in which row of the chess board. That is, if t[0]==5, then it means that the queen has been placed in the fifth column of the first row. We need to couple the backtracking algorithm with a procedure that checks whether the tuple is completable or not, i.e. to check that the next placed queen 'i' is not menaced by any of the already placed 'j' (j < i):
//Two queens are in the same column         if t[i]=t[j]
//Two queens are in the same major diagonal if (t[i]-t[j])=(i-j)
//two queens are in the same minor diagonal if (t[j]-t[i])=(i-j)
//Here is some working C code to solve this problem using backtracking


# include<stdio.h>
# include<conio.h>
int t[9];
void queens(int i);
int empty(int i);
void print_solution();

int main()
{
  queens(1);
  print_solution();
  getch();
  return(0);
}

void queens(int i)
{
  for(t[i]=1;t[i]<=8;t[i]++)
  {
    if(empty(i))
    {
       if(i==8)
       {
          print_solution();
          getch();
          /* If this exit is commented, it will show ALL possible combinations */
		  exit (1);
       }
       else
       {
          // Recurse!
          queens(i+1);
       }

    }// if

  }// for
}
int empty(int i)
{
  int j;
  j=1;
  while(t[i]!=t[j] && abs(t[i]-t[j])!=(i-j) && j<8)j++;
  return((i==j)?1:0);
}

void print_solution()
{
  int i;
  for(i=1;i<=8;i++)printf("\nt[%d] = [%d]",i,t[i]);
}
