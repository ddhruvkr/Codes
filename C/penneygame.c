# include <stdio.h>
# include <string.h>
# include <conio.h>
int main()
{
	int t,i,n,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0;
	char a[40];
	char c[4];
	
	scanf("%d" , &t);
	//printf("yeah\n");
	while(t--) {
		s1=0;s2=0;s3=0;s4=0;s5=0;s6=0;s7=0;s8=0;
		scanf("%d" , &n);
		scanf("%s",a);
		for(i=0;i<38;i++) {
			c[0]=a[i];
			c[1]=a[i+1];
			c[2]=a[i+2];
			c[3] = '\0';
			//printf("%s\n" , c);
			if(strcmp(c,"TTT")==0)s1++;
			else if(strcmp(c,"TTH")==0)s2++;
			else if(strcmp(c,"THT")==0)s3++;
			else if(strcmp(c,"THH")==0)s4++;
			else if(strcmp(c,"HTT")==0)s5++;
			else if(strcmp(c,"HTH")==0)s6++;
			else if(strcmp(c,"HHT")==0)s7++;
			else if(strcmp(c,"HHH")==0)s8++;
		}
		printf("%d %d %d %d %d %d %d %d %d\n" , n,s1,s2,s3,s4,s5,s6,s7,s8);
	}
	getch();
	return 0;
}
