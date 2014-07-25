# include <cstdio>
# include <vector>
using namespace std;
vector <int> v;
int power(int x , int y)
{
    int result= 1;
    while(y>0)
    {
        if(y%2==1){
            result=(result*x);
        }
        y=y>>1;
        x=(x*x);
    }
    return result;
}
int main() {
	int n,m,p,j,r,i,k,max,t,a,ch1,ch2,rc;
	char s[2];
	scanf("%d%d",&n,&m);
	p=power(2,n);
	max=0;
	for(i=0;i<p;i++){
		scanf("%d",&a);
		v.push_back(a);
		if(v[i]>max) {
			max=v[i];
			j=i;
		}
	}
	for(i=0;i<m;i++) {
		scanf("%s",s);
		if(s[0]=='W')printf("%d\n",j+1);
		else if(s[0]=='R') {
			scanf("%d%d",&ch1,&ch2);
			v[ch1-1]=ch2;
			if(ch2 > max) {
				max = ch2;
				j = ch1-1;
			}
			else if((ch1-1) == j) {
				max=0;
				for(k=0;k<p;k++) {
					if(max < v[k]) {
						max=v[k];
						j=k;
					}
				}
			}
		}
		else if(s[0]=='S') {
			scanf("%d",&ch1);
			ch1--;
			r=1;
			t=0;
			if(ch1 == j)printf("%d\n",n);
			else {
				int gn = ch1;
				int x = 1;
				while (x != p) {
					if (gn % 2 == 0) rc = gn + 1;
					else rc = gn - 1;
					for (k = rc * x; k < ((rc * x) + x); k++) {
						if (v[k] > v[ch1]) {
							t = 1;
							break;
						}
					}
					if (t) break;
					r++;
					x = x * 2;
					gn = ch1 / x;
				}
				printf("%d\n",r-1);
			}
		}
	}
	return 0;
}
