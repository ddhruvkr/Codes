#include <stdio.h>
//#include <iostream>

//using namespace std;

struct books
    {
    char name[20];
    int pages;
    int booksabove;
    }b[1000002];
	
int main() {
	int n, i = 0, t;
	char s[20];
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &t);
		b[0].pages = 100001;
		if(t == 0)scanf("%s", s);
		
		else if(t > 0) {
			if(t <= b[i].pages) {
				i++;
				scanf("%s", b[i].name);
            	b[i].pages = t;
            	b[i].booksabove = 0;
			}
			else {
                scanf("%s", s);
				b[i].booksabove++;
			}
		}
		
		else if(t == -1) {
			printf("%d %s\n", b[i].booksabove, b[i].name);
			i--;
		}
	}
	return 0;
}
