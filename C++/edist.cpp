#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a, int b) {
   return a < b ? a : b;
}
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}
int T[2100][2100];
int main()
{
	int t,i,j;
    char X[2100]; 
    char Y[2100]; 
    scanf("%d",&t);
    while(t--) {
    	scanf("%s",X);
		scanf("%s",Y);
		int cost = 0;
    	int leftCell, topCell, cornerCell;
    	int m = strlen(X)+1;
    	int n = strlen(Y)+1;
    	for(i = 0; i < m; i++)
        	T[i][0] = i*1;
    	for(j = 0; j < n; j++)
        	T[0][j] = j*1;
    	for(i = 1; i < m; i++)
    	{
        	for(j = 1; j < n; j++)
        	{
            	leftCell = T[i][j-1];//deletion
            	leftCell += 1;
            	topCell = T[i-1][j];//insertion
            	//if(i == 1 && j == 2)printf("%d/n", topCell);
            	topCell += 1;
            	cornerCell = T[i-1][j-1] ;//replace
            	//if(i == 1 && j == 2)printf("%d/n", cornerCell);
				if(X[i-1] != Y[j-1])cornerCell+=1;
				printf("%d %d %d\n", leftCell, topCell, cornerCell);
            	T[i][j] = Minimum(leftCell, topCell, cornerCell);
        	}
    	}
        for(i = 0; i < m; i++)
		{
    		for(j = 0; j < n; j++)
    		{
				printf("%d  ", T[i][j]);
    		}
    		printf("\n");
		}
        printf("%d\n", T[m-1][n-1] );
	}
    return 0;
}
