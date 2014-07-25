# include <cstdio>
# include <conio.h>
using namespace std;
int main()
{
	int n,k,s,i,j,max1,max2,c1,c2;
	scanf("%d" , &n);
	scanf("%d" , &k);
	int a1[n],a2[n],b1[n],b2[n],sum1[n],sum2[n],a[n],b[n];
	for(i=0;i<n;i++) {
		a1[i]=-1;
		a2[i]=-1;
		b1[i]=-1;
		b2[i]=-1;
	}
	for(i=0;i<n;i++)scanf("%d" , &a[i]);
	for(i=0;i<n;i++)scanf("%d" , &b[i]);
    //printf("a ");
	//for(i=0;i<n;i++)printf("%d " , a[i]);
	//printf("\n");
	//printf("b ");
	//for(i=0;i<n;i++)printf("%d " , b[i]);
	//printf("\n");
	s=0;
	for(i=0;i<n;i++) {
		s=s+a[i];
		sum1[i]=s;
	}
	s=0;
	for(i=0;i<n;i++) {
		s=s+b[i];
		sum2[i]=s;
	}
	//printf("sum1 ");
	//for(i=0;i<n;i++)printf("%d " , sum1[i]);
	//printf("\n");
	//printf("sum2 ");
	//for(i=0;i<n;i++)printf("%d " , sum2[i]);
	//printf("\n");
	for(i=1;i<n;i++) {
		if(sum1[i]+b[i]<=k) {
			a1[i]=sum1[i]+b[i];
			a2[i]=i;
			if(i!=n-1)
			for(j=i+1;j<n;j++) {
				if(a1[i]+b[j]<=k){a1[i]=a1[i]+b[j];a2[i]=j;}
				else j=n;
			}
		}
		else if(sum1[i]<=k){a1[i]=sum1[i];a2[i]=i;}
	}

	//printf("a1 ");
	//for(i=0;i<n;i++)printf("%d " , a1[i]);
	//printf("\n");
	//printf("a2 ");
	//for(i=0;i<n;i++)printf("%d " , a2[i]);
	//printf("\n");
	for(i=1;i<n;i++) {
		if(sum2[i]+a[i]<=k) {
            b1[i]=sum2[i]+a[i];
            b2[i]=i;
			if(i!=n-1)
			for(j=i+1;j<n;j++) {
				if(b1[i]+a[j]<=k){b1[i]=b1[i]+a[j];b2[i]=j;}
				else j=n;
			}
		}
		else if(sum2[i]<=k){b1[i]=sum2[i];b2[i]=i;}
	}
	//printf("b1 ");
	//for(i=0;i<n;i++)printf("%d " , b1[i]);
	//printf("\n");
	//printf("b2 ");
	//for(i=0;i<n;i++)printf("%d " , b2[i]);
	//printf("\n");
	max1=0;
	max2=0;
	for(i=0;i<n;i++) {
		if(a2[i]>max1){max1=a2[i];c1=i;}
        if(b2[i]>max2){max2=b2[i];c2=i;}
	}
	if(max1>max2)printf("%d %d\n" , max1+1,a1[c1]);
	else if(max1<max2)printf("%d %d\n" , max2+1,b1[c2]);
	else if(max1==max2) {
        if(a1[c1]<b1[c2])printf("%d %d\n" ,max1+1, a1[c1]);
		else if(a1[c1]>b1[c2])printf("%d %d\n" ,max2+1, b1[c2]);
		else printf("%d %d\n" ,max2+1, b1[c2]);
	}
	getch();
	return 0;
}
