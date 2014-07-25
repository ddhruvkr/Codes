# include <stdio.h>
# include <conio.h>
# include <math.h>
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
		char t[n];
		for(i=0;i<n;i++)t[i] = '0';
		long int s = 0;
		n--;
		long int k = n;
		long int p=s+1;
		while(n!=0) {
			while ( t[p] == '$')
			{
				if(p == k)p=0;
				else p++;
			}
			t[p] = '$';
			n--;
			if(p==k)p=0;
			else p++;
			while ( t[p] == '$')
			{
				if(p == k)p=0;
				else p++;
			}
			if(p==k)p=0;
			else p++;
			                                                                                                                                                                                                                                                              while (t[s] == '$')s++;
		}
		for(s=0;s<=k;s++)if(t[s]!='$'){printf("%ld\n" , s+1);continue;}
		gets(a);
		if((a[0] == '0') && (a[1] == '0') && (a[3] == '0'))m=0;
	}
	getch();
	return 0;
}
