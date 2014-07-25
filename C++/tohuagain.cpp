# include <stdio.h>
int main()
{
	char a[100];
	int t,i,n,br;
	char ch;
	scanf("%d" , &t);
	while(t--) {
		i=1;
		while(i!=100) {
			scanf("%d" , &n);
			scanf("%c" , &ch);
			scanf("%c" , &a[i]);
			i++;
		}
		ch=a[9];
		br=0;
		for(i=18;i<=81;i+=9)if(a[i]!=ch){
			br=1;
			break;
		}
		if(br==1)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
