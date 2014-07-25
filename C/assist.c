# include <stdio.h>
# include <conio.h>
int main()
{
	int n,a=2,j,i;
	scanf("%d" , &n);
	while(n!=0) {
		a=2;
		int c[1000];
		int p=1;
		for(i=0;i<1000;i++){c[i]=a;a++;}
		//for(i=0;i<12;i++)printf("%d ",c[i]);
		//printf("\n");
		a=0;
		while(p!=n) {
			if(c[a]!=-999) {
				for(j=a+c[a];j<1000;j=j+c[a]) {
					if(j<1000)c[j]=-999;
				}
				a++;
				p++;
			}
			else a++;
			//printf("%d %d \n" , a ,p);
			//for(i=0;i<12;i++)printf("%d ",c[i]);
		//printf("\n");
        }
        //printf("%d %d \n" , a ,p);
        while(c[a]==-999)a++;
        printf("%d\n" , c[a]);
        scanf("%d" , &n);
	}
	getch();
	return 0;
}
