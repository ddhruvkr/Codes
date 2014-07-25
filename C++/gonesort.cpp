/*
We first should find longest consecutive increasing subsequence, which can be done in O(n log n) (by sorting array), after that, the number of changes needed is N - longest consecutive increasing subsequence. Note that by consecutive I mean there order in sorted array.
e.g:
1 7 6 2 5 4 3 => 1-2-3 is longest consecutive increasing subsequence, number of moves needed is 4.
1 6 4 3 5 2 7 => 1-2 or 4-5 or 6-7 is longest consecutive increasing subsequence, note that 1-4-5-7 is longest increasing subsequence but number of moves needed is 5 not 3.
Why this works:
Best algorithm does not changes some of a items places, call biggest subsequence without changes as X, you wont change the position of X items related to each other during operations, so they should be sorted in increasing mode. But because you just allowed to move some items in the first or the last of array, you can't put any item between X items (note that we assumed X is biggest unchanged subsequence during operations), So there should be no gap between X items. so they should be sorted and consecutive in sorted format.
So number of changes needed couldn't be smaller than the N- length of X, but also is not hard to do your job with N-length of X operation.

here is the implementation of above idea:
*/



# include<stdio.h>
typedef long LL;
int main()
{
    LL i, j, N;
    int test;
    scanf("%d", &test);
    while (test--) {
 scanf("%d", &N);
 LL a[N];
 LL LS[N];
 LL largest;
 for (i = 0; i < N; i++)
     scanf("%ld", &a[i]);

 for (i = 0; i < N; i++) {
     LS[i] = 1;
     for (j = 0; j < i; j++) {
  if (LS[i] <= LS[j] && a[i] == (a[j] + 1))
      LS[i] = LS[j] + 1;
     }
 }
 largest = 0;
 for (i = 0; i < N; i++) {
     if (LS[i] > largest)
  largest = LS[i];
 }

 printf("%ld\n", N - largest);
    }


    return 0;
}
