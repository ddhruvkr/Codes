# include <stdio.h>
# include <conio.h>
# include <string.h>
int main()
{
	int t,n,p;
	char s[50001];
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &n);
		scanf("%s" , s);
		p=strlen(s);
		printf("%c\n" , s[p-1]);
	}
	getch();
	return 0;
}
