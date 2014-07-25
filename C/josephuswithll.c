# include <stdio.h>
# include <conio.h>
# include <math.h>
struct node {
	long int data;
	struct node *next;
};
int main()
{
	char a[4];
	long int i,n;
	gets(a);
	int m = 1;
	if((a[0] == '0') && (a[1] == '0') && (a[3] == '0'))m=0;
	while (m==1)
	{
		long int n = ((10 * ((int)(a[0])-48) + ((int)(a[1])-48)) * pow(10 , ((int)(a[3])-48)));
		struct node *p , *t , *c;
		p = (struct node *)malloc(sizeof(struct node));
		p->data = 1;
		t = p;
		for(i=2;i<=n;i++) {
			p->next = (struct node *)malloc(sizeof(struct node));
			p = p->next;
			p->data = i;
		}
		p->next = t;
		p = t;
		//for(i=0;i<n;i++){printf("%ld " , p->data);p = p->next;}
		p = t;
		n--;
		while(n!=0) {
			c = p;
			t = p->next;
			p = t->next;
			c->next = p;
			free(t);
			n--;
		}
		printf("%ld\n" , p->data);
		gets(a);
		if((a[0] == '0') && (a[1] == '0') && (a[3] == '0'))m=0;
	}
	getch();
	return 0;
}
