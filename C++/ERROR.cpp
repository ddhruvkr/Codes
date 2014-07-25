#include <stdio.h>
#include <string.h>

char s[100005];
int m = 3;
int n, stop;
char pattern1[] = "010";
char pattern2[] = "101";
int f2[5], f1[5];

void failure1() {
	int i, j;
	f1[0] = f1[1] = 0;
	for(i = 2; i <= m; i++) {
		j = f1[i - 1];
		while(1) {
			if(pattern1[j] == pattern1[i - 1]) {
				f1[i] = j + 1;
				break;
			}
			if(j == 0) {
				f1[i] = 0;
				break;
			}
			j = f1[j];
		}
	}
}

void failure2() {
	int i, j;
	f2[0] = f2[1] = 0;
	for(i = 2; i <= m; i++) {
		j = f2[i - 1];
		while(1) {
			if(pattern2[j] == pattern2[i - 1]) {
				f2[i] = j + 1;
				break;
			}
			if(j == 0) {
				f2[i] = 0;
				break;
			}
			j = f2[j];
		}
	}
}


void kmp(char pattern[3], int f[5]) {
	//failure(pattern);
	int i = 0;
	int j = 0;
	while(1) {
		if(j == n)break;
		else if(s[j] == pattern[i]) {
			i++;
			j++;
			if(i == m) {
				stop = 1;
				return;
			}
		}
		else if(i > 0)i = f[i];
		else j++;
	}
}

string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

int main() {
	int t;
	scanf("%d", &t);
	failure1();
	failure2();
	while(t--) {
		scanf("%s", s);
	    n = strlen(s);
	    stop = 0;
		kmp(pattern1, f1);
		if(stop == 1)printf("Good\n");
		else {
			kmp(pattern2, f2);
			if(stop == 1)printf("Good\n");
			else printf("Bad\n");
		}
	}
	return 0;
}
