# include <stdio.h>
# include <string.h>
# include <stdlib.h>
char int2string(int n)
    {
        string s="";
        while(n) s=char(n%10+'0') + s,n/=10;
        return s;
    }
int string2int(string s)
    {
        int tmp=0;
        for(int i=0;i<s.size();i++) tmp=tmp*10+(s[i]-'0');
        return tmp;
    }
int func(int i)
{
	char s[15],str[15];
	int l,br,abs,t,d;
	s=int2string(i);
    l=strlen(s);
	br=0;
	t=0;
	l--;
	while(br==0 && t<l) {
		if(s[l]=='0') {
			l--;
		}
		else br=1;
	}
	for(t=0;t<=l;t++)str[t]=s[t];
	str[t+1]='\0';
	l=strlen(str);
	d=string2int(str);
	if(d%10==5)abs=2*l-1;
	else abs=2*l;
	return abs;
}
int main()
{
	int br=1,t,w,a,d1,d2,s,i,e;
	//double d1,double d2;
	char str[15],s1[15],s2[15];
	scanf("%d",&w);
	while(w--) {
		scanf("%d",&s);
		a=func(s);
		d1=0.95*s;
		d2=1.05*s;
		s1=int2string(d1);
		s2=int2string(d2);
		//itoa(d1,s1,10);
		//itoa(d2,s2,10);
		br=1;
		t=0;
		while(br==1) {
			if(s1[t]!=s2[t]) {
				if(s1[t]<'5' && s2[t]>='5')e=2*(t+1)-1;
				else e=2*(t+1);
				br=0;
			}
			else t++;
		}
		if(e<a)
			printf("absurd\n");
		else printf("not absurd\n");
	}
	return 0;
}
