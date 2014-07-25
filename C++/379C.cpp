#include <stdio.h>
#include <stdlib.h>

int a[300005], id[300005], b[300005];
int comparator(const void *x, const void *y)
	{
    	return ( a[*(int*)x] - a[*(int*)y] );
	}
	
int main() {
	int  n, i, l;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		id[i] = i;
	}
	qsort(id, n, sizeof(int), comparator);
	l = a[id[0]];
	b[id[0]] = l;
	for(i = 1; i < n; i++) {
		if(a[id[i]] == a[id[i-1]]) b[id[i]] = ++l;
		else if(a[id[i]] > l){
			b[id[i]] = a[id[i]];
			l = a[id[i]];
		}
		else b[id[i]] = ++l;
	}
	for(i = 0; i < n; i++)printf("%d ", b[i]);
	printf("\n");
	return 0;
}
