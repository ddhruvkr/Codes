# include <stdio.h>
# include <conio.h>

void add(int s1[] , int s2[])
{
	int c[4];
	int d=0,i;
	for(i=3;i>=0;i--) {
		d =d/10 + s1[i] + s2[i];
		c[i] = d%10;
	}
	if(c[0] == 1)printf("m");
	else if(c[0] != 0)printf("%dm" , c[0]);
	if(c[1] == 1)printf("c");
	else if(c[1] != 0)printf("%dc" , c[1]);
	if(c[2] == 1)printf("x");
	else if(c[2] != 0)printf("%dx" , c[2]);
	if(c[3] == 1)printf("i");
	else if(c[3] != 0)printf("%di" , c[3]);
	printf("\n");
}

int main()
{
	int n,i=0,j,m,w,q;
	int s1[4],s2[4];
	scanf("%d" , &w);
	for(q=0;q<w;q++) {
	for(i=0;i<4;i++) {
		s1[i] = 0;
		s2[i] = 0;
	}
	scanf("%d" , &n);
	char c[17];
	//fflush(stdin);
	scanf("%[^\n]s" , c);
	printf("%s\n" , c);
	j=0;
	m=0;
	if(c[0] == 'm'){s1[0] = 1;j++;}
	else if(c[0] == 'c'){s1[1] = 1;j++;}
	else if(c[0] == 'x'){s1[2] = 1;j++;}
	else if(c[0] == 'i'){s1[3] = 1;j++;}
	while(c[j]!='\0') {
		if(c[j] == ' ') {
			m=1;
			j++;
			if(c[j] == 'm')s2[0] = 1;
			else if(c[j] == 'c')s2[1] = 1;
			else if(c[j] == 'x')s2[2] = 1;
			else if(c[j] == 'i')s2[3] = 1;
		}
		if(c[j] == '2' || c[j] == '3' || c[j] == '4' || c[j] == '5' || c[j] == '6' || c[j] == '7' || c[j] == '8' || c[j] == '9') {
			if(c[j+1] == 'm') {
				if(m == 0)s1[0] = (int)c[j] - 48;
				else s2[0] = (int)c[j] - 48;
			}
			else if(c[j+1] == 'c') {
				if(m == 0)s1[1] = (int)c[j] - 48;
                else s2[1] = (int)c[j] - 48;
			}
			else if(c[j+1] == 'x') {
				if(m == 0)s1[2] = (int)c[j] - 48;
                else s2[2] = (int)c[j] - 48;
			}
			else if(c[j+1] == 'i') {
				if(m == 0)s1[3] = (int)c[j] - 48;
				else s2[3] = (int)c[j] - 48;
			}
			j = j+2;
		}
        else if(c[j] == 'm') {
			if (m == 0){s1[0] = 1;j++;}
			else {s2[0] = 1;j++;}
        }
		else if(c[j] == 'c') {
			if(m == 1){s1[1] = 1; j++;}
			else {s2[1] = 1;j++;}
		}
		else if(c[j] == 'x') {
			if(m == 0){s1[2] = 1;j++;}
			else {s2[2] = 1;j++;}
		}
		else if(c[j] == 'i') {
			if(m == 0){s1[3] = 1;j++;}
            else {s2[3] = 1;j++;}
		}
	}
	add(s1 , s2);
	}
	getch();
	return 0;
}
