# include <stdio.h>

void tower(int n , char s , char m , char f) {
          if(n!=0) {
                   tower(n-1 , s , f , m);
                   printf("Moving %d disk from %c to %c\n", n , s , f);
                   tower(n-1 , m , s , f);
          }
}

int main() {
    char s='L',m='C',f='R';
    int n;
    scanf("%d",&n);
    tower(n,s,m,f);
    getch();
    return 0;
}
           
