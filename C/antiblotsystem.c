# include <stdio.h>
# include <string.h>
int main()
{
	int t,l1,p,m,i;
	char a[50],b[50],c[50];
	char ch;
	scanf("%d",&t);
	while(t--) {
		scanf("%s" , a);
		scanf("%c",&ch);
		scanf("%c",&ch);
		scanf("%c",&ch);
		scanf("%s" , b);
		scanf("%c",&ch);
		scanf("%c",&ch);
		scanf("%c",&ch);
		scanf("%s" , c);
		m=0;
		l1=strlen(a);
		for(i=0;i<l1;i++)if(a[i]=='m') {
			p=atoi(c)-atoi(b);
			printf("%d + %s = %s\n",p,b,c);
			m=1;
			break;
		}
		if(m==0) {
		l1=strlen(b);
		for(i=0;i<l1;i++)if(b[i]=='m') {
			p=atoi(c)-atoi(a);
			printf("%s + %d = %s\n",a,p,c);
			m=1;
			break;
		}
	}
		if(m==0) {
			l1=strlen(c);
		for(i=0;i<l1;i++)if(c[i]=='m') {
			p=atoi(b)+atoi(a);
			printf("%s + %s = %d\n",a,b,p);
			m=1;
			break;
		}
	}
	}
	return 0;
}
