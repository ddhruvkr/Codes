# include <stdio.h>
# include <conio.h>
# include <malloc.h>
struct node {
	int data , height;
	struct node *left;
	struct node *right;
};
int height(struct node *root)
{
	int l , r;
	if(root == NULL)return-1;
	l = height(root->left);
	r = height(root->right);
	if(l > r)root->height =  1+l;
	else root->height = 1+r;
	return root->height;
}
struct node *rotateleft(struct node *root)
{
	struct node *p;
	p = root->right;
	root->right = p->left;
	p->left = root;
	return p;
}
struct node *rotateright(struct node *root)
{
	struct node *p;
	p = root->left;
	root->left = p->right;
	p->right = root;
	return p;
}
struct node *doublerotateleft(struct node *root)
{
	root->right = rotateright(root->right);
	root = rotateleft(root);
}
struct node *doublerotateright(struct node *root)
{
	root->left = rotateleft(root->left);
	root = rotateright(root);
}
void inorder(struct node *root)
{
     if(root != NULL){
             inorder(root->left);
             printf("%d\t%d\n",root->data,root->height);
             inorder(root->right);
     }
}
struct node *insert(struct node *root , int data)
{
	if(root == NULL) {
		root = (struct node *)malloc(sizeof(struct node));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if(root->data > data) {
		root->left = insert(root->left , data);
		if((height(root->left) - height(root->right)) == 2) {
			if(root->left->data > data)root = rotateright(root);
		    else root = doublerotateright(root);
        }
	}
	else if(root->data < data) {
		root->right = insert(root->right , data);
		if((height(root->left) - height(root->right)) == -2) {
			if(root->right->data < data)root = rotateleft(root);
		    else root = doublerotateleft(root);
        }
	}
	return root;
}
struct node *delete(struct node * root , int data ) {
    struct node *p , *p2;
    if ( root->data == data) {
        if ( root->left == root->right )
        return NULL;
        else if ( root->left == NULL ) {
            p = root->right;
            return p;
        }
        else if ( root->right == NULL ) {
            p = root->left;
            return p;
        }
        else {
			p = root->right;
			while(p->left != NULL) {
				p2 = p;
				p = p->left;
			}
			root->data = p->data;
			root->right = delete(root->right , p->data);
			return root;
        }
    }
    if ( root->data < data ) {
        root->right = delete ( root->right , data );
        if((height(root->left) - height(root->right)) == 2) {
			if(height(root->left->left) > height(root->left->right))root = rotateright(root);
			else root = doublerotateright(root);
		}
    }
    else {
        root->left = delete ( root->left , data );
        if((height(root->left) - height(root->right)) == -2) {
			if(height(root->right->right) > height(root->right->left))root = rotateleft(root);
		    else root = doublerotateleft(root);
		}
    }
    printf("%d\n" , root->data);
    //printf("%d\n" , root->left->data);
    //printf("%d\n" , root->right->data);
    return root;
}
int main()
{
	int i , n;
	struct node *root;
	root = NULL;
	scanf("%d" , &n);
	int a[n];
	for(i=0;i<n;i++)scanf("%d" , &a[i]);
	for(i=0;i<n;i++)root = insert(root , a[i]);
	height(root);
	inorder(root);
	root = delete(root , 2);
	inorder(root);
	printf("%d\n" , root->data);
    printf("%d\n" , root->left->data);
    printf("%d\n" , root->right->data);
	getch();
	return 0;
}
