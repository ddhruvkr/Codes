#include <stdio.h>
#include <conio.h>
#include <cstring>
using namespace std;

bool bpm(bool gr[6][6], bool seen[6], int match[6], int u) {
	for(int v = 0; v < 6; v++) {
		if(gr[u][v] == true && seen[v] == false) {
			seen[v] = true;
			if(match[v] == -1 || bpm(gr, seen, match, match[v])) {
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int maxbpm(bool gr[6][6]) {
	bool seen[6];
	int match[6];
	memset(match, -1, sizeof(match));
	int result = 0;
	for(int i = 0; i < 6; ++i) {
        memset(seen, 0, sizeof(seen));
		if(bpm(gr, seen, match, i))result++;
	}
	return result;
}

int main() {
    bool bpGraph[6][6] = {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };
    printf("Maximum number of applicants that can get job is %d", maxbpm(bpGraph));
    getch();
    return 0;
}
