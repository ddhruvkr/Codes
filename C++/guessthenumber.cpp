# include <cstdio>
using namespace std;
int lcm(int a , int b)
{
	if(a > b){
		int i=2;
		while(a%b!=0){a=a*i;i++;}
		return a;
	}
	else {
		int i=2;
		while(b%a!=0){b=b*i;i++;}
		return b;
	}
}

/*inline int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

inline int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}*/

int main() {
	char guess[32];
	int ans, i, j, store[32];
	while(fgets(guess, 32, stdin) && guess[0]!='*') {
		for(i = j = 0, ans = 1; ; i++) {
			if(guess[i]=='Y') ans = lcm(ans, i + 1);
			else if(guess[i]=='N') store[j++] = i + 1;
			else break;
		}
		for(i = 0; i < j && ans % store[i]; i++);
		printf("%d\n", ((i==j)? ans : -1));
	}
	return 0;
}
