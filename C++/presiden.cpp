# include <cstdio>
# include <algorithm>
using namespace std;
int main()
{
	int t,c,v,max,max1,i,j,num,num1,count;
	char ch;
	int a[200][200];
	int arr[200];
	scanf("%d",&t);
	while(t--) {
		scanf("%d%c%d",&c,&ch,&v);
		for(i=0;i<v;i++) {
			for(j=0;j<c;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		for(i=1;i<=c;i++)arr[i]=0;
		for(i=0;i<v;i++) {
			arr[a[i][0]]++;
		}
		count=(v)/2;
		max=0;
		for(i=1;i<=c;i++) {
			if(arr[i]>count && arr[i]>max){
				max=arr[i];
				num=i;
			}
		}
		if(max!=0)printf("%d 1\n",num);
		else {
			max=arr[1];num=1;
			for(i=2;i<=c;i++) {
				if(max<arr[i]){max=arr[i];num=i;}
			}
			max=0;
			for(i=1;i<=c;i++) {
				if(i!=num && arr[i]>max){max=arr[i];num1=i;}
			}
			max=0;max1=0;
			for(i=0;i<v;i++) {
				for(j=0;j<c;j++) {
					if(a[i][j]==num) {
						max++;j=c;
					}
					else if(a[i][j]==num1) {
						max1++;j=c;
					}
				}
			}
			if(max>max1)printf("%d 2\n",num);
			else printf("%d 2\n",num1);
		}
	}
	return 0;
}
