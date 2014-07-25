# include <cstdio>
# include <algorithm>
# include <cstring>
using namespace std;
int main() {
	int t, len;
	char s[21];
	scanf("%d" , &t);
	while(t--) {
		scanf("%d" , &len);
		scanf("%s" , s);
		if(next_permutation(s , s + len))printf("%s\n" , s);
		else printf("ERROR\n");
	}
	return 0;
}
