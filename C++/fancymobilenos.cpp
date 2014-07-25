# include <cstdio>
# include <cmath>
# include <conio.h>
int main()
{
	int t,s,q,i;
	scanf("%d" , &t);
	while(t--) {
		s=1;
		char c[30];
		scanf("%s" , c);
		char ch=c[0];
		q=1;
		for(i=1;c[i]!='\0';i++) {
			if(ch != (c[i])){s=s*pow(2,q-1); q=1;ch=c[i];
			}
			else {q++;
			}
		}
		s=s*pow(2,q-1);
		printf("%d\n" , s);
		s=1;
	}
	getch();
	return 0;
}
