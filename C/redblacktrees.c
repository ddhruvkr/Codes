# include <stdio.h>
# include <conio.h>
# include <malloc.h>

struct node {
	char c;
	int key;
	struct node *left , *right , *p;
};
struct node *root , *nil;

void leftrotate(struct node *x)
{
	struct node *y;
	y = x->right;
	x->right = y->left;
	if(y->left != nil)y->left->p = x;
	y->p = x->p;
	if(x->p == nil)root = y;
	else if(x == x->p->left)x->p->left = y;
	else x->p->right = y;
	y->left = x;
	x->p = y;
}

void rightrotate(struct node *x)
{
	struct node *y;
	y = x->left;
	x->left = y->right;
	if(y->right != nil)y->right->p = x;
	y->p = x->p;
	if(x->p == nil)root = y;
	else if(x == x->p->right)x->p->right = y;
	else x->p->left = y;
	y->right = x;
	x->p = y;
}

void rbinsertfixup(struct node *z)
{
	struct node *y;
	while(z->p->c == 'r') {
    	if(z->p == z->p->p->left) {
			y = z->p->p->right;
			if(y->c == 'r') {
				z->p->c = 'b';
				y->c = 'b';
				z->p->p->c = 'b';
				z = z->p->p;
			}
			else if(z == z->p->right) {
				z = z->p;
				leftrotate(z);
				z->p->c = 'b';
				z->p->p->c = 'r';
				rightrotate(z->p->p);
			}
		}
		else {
			y = z->p->p->left;
			if(y->c == 'r') {
				z->p->c = 'b';
				y->c = 'b';
				z->p->p->c = 'b';
				z = z->p->p;
			}
			else if(z == z->p->left) {
				z = z->p;
				rightrotate(z);
				z->p->c = 'b';
				z->p->p->c = 'r';
				leftrotate(z->p->p);
			}
		}
	}
	root->c = 'b';
}

void rbinsert(struct node *z)
{
	struct node *x , *y;
	y = nil;
	x = root;
	while(x != nil) {
		y = x;
		if(z->key < x->key)x = x->left;
		else x = x->right;
	}
	z->p = y;
	if(y == nil)root = z;
	else if(z->key < y->key)y->left = z;
	else y->right = z;
	z->left = nil;
	z->right = nil;
	z->c = 'r';
	rbinsertfixup(z);
}

void inorder(struct node *root)
{
     if(root != nil){
             inorder(root->left);
             printf("%d\t%c\n",root->key,root->c);
             inorder(root->right);
     }
}

int main()
{
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Inorder print\n");
	printf("4. Count\n");
	printf("5. Exit\n");
	int ch;
	nil = (struct node *)malloc(sizeof(struct node));
	//root = (struct node *)malloc(sizeof(struct node));
	nil->c = 'b';
	root = nil;
	scanf("%c" , &ch);
	while(ch != '5') {
		if(ch == '1') {
			struct node *z;
			z = (struct node *)malloc(sizeof(struct node));
			scanf("%d" , &z->key);
			rbinsert(z);
		}
		else if(ch == '3')inorder(root);
		scanf("%c" , &ch);
	}
	getch();
	return 0;
}
