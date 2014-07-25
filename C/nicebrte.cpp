#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node {
	char i;
	struct node *left;
	struct node *right;
};
int i;

int depth(struct node *p) {
	if (p == NULL)
		return 0;
	int l = depth(p->left);
	int r = depth(p->right);

	return l >= r ? l + 1 : r + 1;
}

void insert(struct node ** p, char a) {
	if (*p != NULL)
	if ((*p)->i == 'l')
		return;
	if (*p == NULL) {
		*p = (struct node *) malloc (sizeof(struct node));
		(*p)->i = a;
		(*p)->left = NULL;
		(*p)->right = NULL;
		i = 1;
	}

	if (i == 0) {
		insert (&((*p)->left), a);
	}
	if (i == 0) {
		insert(&((*p)->right), a);
	}
}
int main()
{
	char a[10001];
	int x;
	cin >> x;
	while (x--) {
		cin >> a;
		struct node *p = NULL;
		for (int j = 0; j < strlen(a); j++) {
			i = 0;
			insert (&p, a[j]);
		}
		int k = depth(p) - 1;
		cout << k << endl;
	}
	return 0;
}
