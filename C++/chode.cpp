#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
	char s1[27];
	char s2[150000];
	char d[100];
	int i, j, t, l2, temp;
	char temp1;
	scanf("%d", &t);
	gets(d);
	while(t--) {
		char s1[27] = "qwrtyuipasdfgjkzxcvbnmheol";
		//printf("%c\n", s1[2]);
		//gets(s1);
		//printf("\n");
		gets(s2);
		int cnt[27] = {0};
        char a[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
		l2 = strlen(s2);
		for(i = 0; i < l2; i++) {
			if(s2[i] >= 'a' && s2[i] <= 'z')cnt[s2[i] - 'a']++;
			else if(s2[i] >= 'A' && s2[i] <= 'Z')cnt[s2[i] - 'A']++;
		}
        for(i = 0; i < 25; i++)
        {
            for(j = 0; j < 25 - i; j++)
            {
                if(cnt[j] > cnt[j + 1])
                {
                    temp = cnt[j];
                    cnt[j] = cnt[j+1];
                    cnt[j+1] = temp;
                    temp1 = a[j];
                    a[j] = a[j+1];
                    a[j+1]=temp1;
                }
            }
        }
        for(i = 0; i < 26; i++)printf("%c ", a[i]);
        printf("\n");
        for(i = 0; i < 26; i++)printf("%d ", cnt[i]);
        printf("\n");
        for(i = 0; i < l2; i++) {
			for(j = 0; j < 26; j++) {
				if(s2[i] == a[j]) {
					s2[i] = s1[j];
					j = 26;
				}
				else if(s2[i] + 32 == a[j]) {
					s2[i] = s1[j] - 32;
					j = 26;
				}
			}
        }
        printf("%s\n", s2);
	}
	return 0;
}
