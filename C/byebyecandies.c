# include <stdio.h>
# include <conio.h>
# include <math.h>
int main()
{
	int e,f,s,m,E,F,S,M,r,sum;
	double max;
	scanf("%d%d%d%d%d%d%d%d",&e, &f, &s, &m, &E, &F, &S, &M);
	while(e!=-1 && f!=-1 && s!=-1 && m!=-1 && E!=-1 && F!=-1 && S!=-1 && M!=-1) {
		if(E>e && F>f && S>s && M>m)printf("%d %d %d %d\n" , E-e,F-f,S-s,M-m);
		else {
		max=(double)e/E;r=0;printf("%lf\n" , max);
		if(max<(double)f/F){max=(double)f/F;r=1;printf("%lf\n" , max);}
        if(max<(double)s/S){max=(double)s/S;r=2;printf("%lf\n" , max);}
        if(max<(double)m/M){max=(double)m/M;r=3;printf("%lf\n" , max);}
        if(r==0 && e%E!=0)max=ceil(max);
        else if(r==1 && f%F!=0)max=ceil(max);
        else if(r==2 && s%S!=0)max=ceil(max);
        else if(r==3 && m%M!=0)max=ceil(max);
        printf("%lf\n" , max);
		sum = (int)max;
		printf("%d\n" , sum);
		printf("%d %d %d %d %d %d %d %d\n",e, f, s, m, E, F, S, M);
        printf("%d %d %d %d\n" , sum*E-e,sum*F-f,sum*S-s,sum*M-m);
	}
	    scanf("%d%d%d%d%d%d%d%d",&e, &f, &s, &m, &E, &F, &S, &M);
	}
	getch();
	return 0;
}
/*#include <stdio.h>

int main() {
	int a, b, c, d, aa, bb, cc, dd, at, bt, ct, dt, mx;
	while(scanf("%d%d%d%d%d%d%d%d",&a, &b, &c, &d, &aa, &bb, &cc, &dd)==8 && a>=0) {
		at = (a + aa - 1) / aa;
		bt = (b + bb - 1) / bb;
		ct = (c + cc - 1) / cc;
		dt = (d + dd - 1) / dd;
		mx = at;
		mx = mx>bt? mx:bt;
		mx = mx>ct? mx:ct;
		mx = mx>dt? mx:dt;
		printf("%d %d %d %d\n", aa*mx-a, bb*mx-b, cc*mx-c, dd*mx-d);
	}
	return 0;
}*/
