# include <cstdio>
# include <cstring>
# include <cstdlib>
using namespace std;
int func(int n)
    {
            int cnt=0;
            bool f=0;
            while(n%10==0) n/=10;
                        if(n%10==5) f=1;
                        while(n) cnt++,n/=10;

                        if(f==1) return 2*cnt-1;
                        else  return 2*cnt;
    }

int main()
{
	int br=1,t,a,w,i,e,l,e1;
	int s,d1,d2;
	char ch;
	char str[15],s1[15],s2[15];
	scanf("%d",&w);
	while(w--) {
		scanf("%d",&s);
		a=func(s);
		d1=0.95*s;
		d2=1.05*s;
		e=func(d2);
        sprintf(s1, "%d", d1);
        sprintf(s2, "%d", d2);
        
				/*br=1;
				ch=s2[strlen(s2)-1];
				if(s2[strlen(s2)-1]>='5') {
					s2[strlen(s2)-1]='5';
					if(atoi(s2)>d1){e=func(atoi(s2));}
					else {s2[strlen(s2)-1]=ch;br=0;}
				}
    			ch=s2[strlen(s2)-1];
				if(s2[strlen(s2)-1]>='0') {
					s2[strlen(s2)-1]='0';
					if(atoi(s2)>=d1+1){e=func(atoi(s2));}
					else {s2[strlen(s2)-1]=ch;br=0;}
				}*/
				
		if(strlen(s1)<=strlen(s2))l=strlen(s1);
		else l=strlen(s2);
		br=1;
		t=0;
		while(br==1 && t<=l) {
			if(s1[t]!=s2[t]) {
				if(s1[t]<'5' && s2[t]>='5')e=2*(t+1)-1;
				else e=2*(t+1);
				br=0;
			}
			else t++;
		}
		 /*for(i=strlen(s2)-2;i>=1 && br;i--)
            {
                ch=s2[i];
                //char ss=tmp[i];
                if(s2[i]>='5')
                {
                    s2[i]='5';
                    if(atoi(s2)>d1){e=func(atoi(s2));}
					else {s2[i]=ch;br=0;}
                }
                if(s2[i]>='0')
                {
                    s2[i]='0';
                    if(atoi(s2)>d1){e=func(atoi(s2));}
					else {s2[i]=ch;br=0;}
                }
            }*/

		if(e<a)
			printf("absurd\n");
		else printf("not absurd\n");
	}
	return 0;
}
