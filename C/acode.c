# include <stdio.h>
# include <string.h>
int main() {
	long long dp[5001];
	char s[5001];
	int d,i,t,l;
	scanf("%s",s);
	while(strcmp(s,"0")) {
        for(i=1;i<5001;i++)dp[i]=0;
		l=strlen(s);
		d=1;
		dp[0]=1;
		while(d<l) {
			t=(s[d-1]-'0')*10;
			t=t+(s[d]-'0');
			if(s[d]-'0')dp[d]=dp[d-1];
			if(t>9 && t<27) {
				if(d>=2)dp[d]+=dp[d-2];
				else dp[d]+=dp[0];
			}
			d++;
		}
		printf("%lld\n",dp[l-1]);
		scanf("%s",s);
	}
	return 0;
}
