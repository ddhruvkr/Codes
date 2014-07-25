// Dynamic Programming implementation of edit distance
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Change these strings to test the program

#define SENTINEL (-1)
inline
int min(int a, int b) {
   return a < b ? a : b;
}

// Returns Minimum among a, b, c
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}

// Strings of size m and n are passed.
// Construct the Table for X[0...m, m+1], Y[0...n, n+1]

int T[1001][1001];
int main()
{
    char X[1000]; // vertical
    char Y[1000]; // horizontal

    //printf("Minimum edits required to convert %s into %s is %d\n",
    scanf("%s",X);
	while(X[0]!='#') {
		scanf("%s",&Y);
		int cost = 0;
    int leftCell, topCell, cornerCell;

    int m = strlen(X)+1;
    int n = strlen(Y)+1;

    // T[m][n]
    //int *T = (int *)malloc(m * n * sizeof(int));

    // Initialize table
    //for(int i = 0; i < m; i++)
      //  for(int j = 0; j < n; j++)
        //    T[i][j] = -1;

    // Set up base cases
    // T[i][0] = i
    for(int i = 0; i < m; i++)
        T[i][0] = i*15;

    // T[0][j] = j
    for(int j = 0; j < n; j++)
        T[0][j] = j*30;
// for all i and j, d[i,j] will hold the Levenshtein distance between
  // the first i characters of s and the first j characters of t; vb`   1
    // Build the T in top-down fashion
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // T[i][j-1]
            leftCell = T[i][j-1];
            leftCell += 30; // deletion

            // T[i-1][j]
            topCell = T[i-1][j];
            topCell += 15; // insertion

            // Top-left (corner) cell
            // T[i-1][j-1]
            cornerCell = T[i-1][j-1] ;

            // edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
            //cornerCell += (X[i-1] != Y[j-1]);
			if(X[i-1]!=Y[j-1])cornerCell+=45;
			 // may be replace

            // Minimum cost of current cell
            // Fill in the next cell T[i][j]
            T[i][j] = Minimum(leftCell, topCell, cornerCell);
        }
    }

         printf("%d\n", T[m-1][n-1] );
         scanf("%s",&X);
		}
    return 0;
}
