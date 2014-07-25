# include <stdio.h>
# include <conio.h>

int parent(int i)
{
	if(i % 2 == 0)
    return (i / 2-1);
    else return i / 2;
}

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return ((2 * i) + 2);
}

void maxheapify(int arr[], int i, int s)
{
     int largest, t, l, r;
     l = left(i);
     r = right(i);
     if((l <= s) && (arr[l] > arr[i]))largest = l;
     else largest = i;
     if((r <= s) && (arr[r] > arr[largest]))largest = r;
     if( largest != i) {
         t = arr[i];
         arr[i] = arr[largest];
         arr[largest] = t;
         maxheapify(arr, largest, s);
     }
}

void buildmaxheap(int arr[], int n)
{
     int s = n - 1, i;
     for(i = (n/2) - 1; i >= 0; i--)
          maxheapify(arr, i, s);
}

void heapsort(int arr[], int n)
{
    buildmaxheap(arr, n);
    int i, s = n - 1, t;
    for(i = n - 1; i > 0; i--) {
         t = arr[0];
         arr[0] = arr[i];
         arr[i] = t;
         s = s - 1;
         maxheapify(arr , 0 , s);
    }
    return;
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);
	heapsort(arr , n);
    for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
    getch();
    return 0;
}
