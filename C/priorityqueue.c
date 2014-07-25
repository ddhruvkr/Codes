# include <stdio.h>
# include <conio.h>

int parent(int i)
{
	if(i%2==0)
    return (i/2-1);
    else return i/2;
}

int left(int i)
{
    return (2*i+1);
}

int right(int i)
{
    return ((2*i) + 2);
}

void maxheapify(int arr[] , int i , int s)
{
	int largest,t,j,l,r;
	l = left(i);
	r = right(i);
	if(l <= s && arr[l] > arr[i])largest=l;
	else largest=i;
	if(r <= s && arr[r] > arr[largest])largest=r;
	if(largest != i)
	{
		t=arr[i];
		arr[i]=arr[largest];
		arr[largest]=arr[t];
		maxheapify(arr , largest , s);
	}
	//for(j=0;j<i;j++)printf("%d " , arr[j]);
	//printf("\n");
	
}

int heapextractmax(int arr[] , int n)
{
	int max;
	max=arr[0];
	arr[0]=arr[n];
	n--;
	maxheapify(arr , 0 , n);
	return max;
}

void heapincreasekey(int arr[] , int i , int key)
{
	int t,j;
	arr[i] = key;
	while(i > 0 && arr[parent(i)] < arr[i])
	{
		t=arr[i];
		arr[i]=arr[parent(i)];
		arr[parent(i)]=t;
		i=parent(i);
	}
	for(j=0;j<6;j++)printf("%d " , arr[j]);
	printf("\n");
}

void maxheapinsert(int arr[] , int n , int key)
{
	n++;
	arr[n]=-999;
	heapincreasekey(arr , n , key);
}

int main()
{
    int n,i,key;
    scanf("%d" , &n);
    scanf("%d" , &key);
    int arr[15];
    for(i=0;i<n;i++)
    scanf("%d" , &arr[i]);
    maxheapinsert(arr , n-1 , key);
    i=heapextractmax(arr , n);
    //printf("dhruv");
    printf("%d\n",i);
    //for(i=0;i<n;i++)
    //printf("%d " , arr[i]);
    getch();
    return 0;
}
