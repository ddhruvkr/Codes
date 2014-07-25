#include <cstdio>
#include <conio.h>

using namespace std;

bool easiesthardproblem(int a[6], int n) {
	int sum = 0, i, j;
	for(i = 0; i < n; i++)sum = sum + a[i];
	if(sum % 2 != 0)return false;
	else {
		bool arr[sum/2 + 1][n + 1];
		for(i = 0; i <= n; i++)arr[0][i] = true;
		for(i = 1; i <= sum/2; i++)arr[i][0] = false;
		for(i = 1; i <= sum/2; i++) {
			for(j = 1; j <= n; j++) {
				arr[i][j] = arr[i][j - 1];
				if(i >= a[j - 1]) {//if arr[j - 1] is greater than the sum then ignore
					arr[i][j] = arr[i][j-1] || arr[i - a[j - 1]][j - 1];
					//There is a subset of { x1, ..., xj } that does not use xj and that sums to i
					//There is a subset of { x1, ..., xj } that does not use xj and that sums to i - xj (since xj + that subset's sum = i)
				}
			}
		}
		return arr[sum/2][n];
	}
}
/*
space optimized soln
part[0]=1;
for(i=0;i<n;i++)
{
   for(j=sum;j>=arr[i];j--)
   {
        part[j]=part[j] | part[j-arr[i]]
   }
}
if(part[sum])
   printf("\nsubset exists\n");
*/

int main() {
    int arr[] = {3, 1, 1, 2, 2, 1};
  	int n = sizeof(arr)/sizeof(arr[0]);
  	if (easiesthardproblem(arr, n) == true)
     	printf("Can be divided into two subsets of equal sum");
  	else
     	printf("Can not be divided into two subsets of equal sum");
  	getchar();
  	return 0;
}
