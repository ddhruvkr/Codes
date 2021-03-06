# include <stdio.h>
# include <string.h>

#define gc getchar_unlocked

int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}


int cs0[500001], cs1[500001], rs0[500001], rs1[500001], fnr[2][500001], fnc[2][500001];
int max;

void updatec(int x, int idx, int val) {
	while(idx > 0 && idx <= max) {
		fnc[x][idx] += val;
		idx += idx & -idx;
	}
}

void updater(int x, int idx, int val) {
    while(idx > 0 && idx <= max) {
		fnr[x][idx] += val;
		idx += idx & -idx;
	}
}

int readc(int x, int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += fnc[x][idx];
		idx -= idx & -idx;
	}
	return sum;
}

int readr(int x, int idx) {
	int sum = 0;
	while(idx > 0) {
		sum += fnr[x][idx];
		idx -= idx & -idx;
	}
	return sum;
}

int main() {
	int n, q, z = 1, x, y, ans, t, m, i;
	n = read_int();
	q = read_int();
	//scanf("%d%d", &n, &q);
	char s[10];
	max = q;
	for(z = 1; z <= q; z++) {
		scanf("%s", s);
		if(strcmp(s, "ColSet") == 0) {
			//scanf("%d%d", &x, &y);
			x = read_int();
			y = read_int();
			if(cs0[x]||cs1[x])
			if(cs0[x] > cs1[x])updatec(0, cs0[x], -1);
			else updatec(1, cs1[x], -1);
			if(y == 0) {
				cs0[x] = z;
				updatec(0, cs0[x], 1);
			}
			else {
				cs1[x] = z;
				updatec(1, cs1[x], 1);
			}
		}
		else if(strcmp(s, "RowSet") == 0) {
			//scanf("%d%d", &x, &y);
			x = read_int();
			y = read_int();
			if(rs0[x]||rs1[x])
			if(rs0[x] > rs1[x])updater(0, rs0[x], -1);
			else updater(1, rs1[x], -1);
			if(y == 0) {
				rs0[x] = z;
				updater(0, rs0[x], 1);
			}
			else {
				rs1[x] = z;
				updater(1, rs1[x], 1);
			}
		}
		else if(strcmp(s, "RowQuery") == 0) {
			//scanf("%d", &x);
			x = read_int();
			if(rs0[x] >= rs1[x]) {
				ans = readc(1, z) - readc(1, rs0[x]);
				printf("%d\n", n-ans);
			}
			else {
				ans = readc(0, z) - readc(0, rs1[x]);
				printf("%d\n", ans);
			}
		}
		else if(strcmp(s, "ColQuery") == 0) {
			//scanf("%d", &x);
			x = read_int();
            if(cs0[x] >= cs1[x]) {
				ans = readr(1, z) - readr(1, cs0[x]);
				printf("%d\n", n-ans);
			}
			else {
				ans = readr(0, z) - readr(0, cs1[x]);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
