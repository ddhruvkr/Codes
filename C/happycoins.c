# include <stdio.h>
# include <string.h>
int main()
{
	int t,n,count;
	char s[4];
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		count=0;
		while(n--) {
   			scanf("%s",s);
			if(strcmp("lxh",s)==0)count++;
		}
		if(count%2==0)printf("hhb\n");
		else printf("lxh\n");
	}
	return 0;
}
