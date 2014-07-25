# include <stdio.h>
# include <conio.h>
int s[20][2],n=0,a,b,c;

void maze ( char arr[][5] , int i , int j) {
     a=0;b=0;c=0;
     if(arr[i][j-1] == 'F' || arr[i+1][j] == 'F' || arr[i][j+1] == 'F'){printf("Reached Finish at 5,1\n"); exit(0);}
     if(( arr[i][j-1] == '0') && (arr[s[n-1][0]][s[n-1][1]] != arr[i][j-1]))a=1;
     printf("hello");
     if((arr[i+1][j] == '0') && (arr[s[n-1][0]][s[n-1][1]] != arr[i+1][j]))b=1;
     if((arr[i][j+1] == '0') && (arr[s[n-1][0]][s[n-1][1]] != arr[i][j+1]))c=1;
     if(a==1 && b==1 && c==1){s[n][0]=i;s[n++][1]=j+1;s[n][0]=i+1;s[n++][1]=j;s[n][0]=i;s[n++][1]=j;j--;printf("Reached %d %d\n" , i, j);}
     else if(a==1 && c==1){s[n][0]=i;s[n++][1]=j+1;s[n][0]=i;s[n++][1]=j;j--;printf("Reached %d %d\n" , i, j);}
     else if(a==1 && b==1){s[n][0]=i+1;s[n++][1]=j;s[n][0]=i;s[n++][1]=j;j--;printf("Reached %d %d\n" , i, j);}
     else if(b==1 && c==1){s[n][0]=i;s[n++][1]=j+1;s[n][0]=i;s[n++][1]=j;i++;printf("Reached %d %d\n" , i, j);}
     else if(a==1){s[n][0]=i;s[n++][1]=j;j--;printf("Reached %d %d\n" , i, j);}
     else if(b==1){s[n][0]=i;s[n++][1]=j;i++;printf("Reached %d %d\n" , i, j);}
     else if(c==1){s[n][0]=i;s[n++][1]=j;j++;printf("Reached %d %d\n" , i, j);}
     else {n--;i=s[n][0];j=s[n][1];printf("Reached %d %d\n" , i, j);}
     maze (arr, i, j);
}
     
int main() {
    char arr[6][5] = {
                        {'#','#','S','#','#'},
                        {'#','#','0','0','#'},
                        {'#','0','#','0','#'},
                        {'#','#','0','0','#'},
                        {'#','0','0','#','#'},
                        {'#','F','#','#','#'}
                     };
    maze(arr, 0, 2);
    getch();
    return 0;
}
    
    
          
    
          

    
