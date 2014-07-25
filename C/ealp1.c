# include <stdio.h>
# include <conio.h>
int main()
{
	int q,t,n,d,w=0;
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &n);
		q=0;
		w++;
		while(n--) {
			scanf("%d" , &d);
			if(d%10!=0)q++;
		}
		printf("Case %d: %d\n" ,w, q);
	}
	getch();
	return 0;
}
