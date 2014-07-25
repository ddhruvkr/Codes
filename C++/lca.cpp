#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left, *right;
};

struct node *lca(struct node* root, int n1, int n2){
	while(root != NULL){
		if(root->data == n1)return root;
		else if(root->data == n2)return root;
		else if(root->data > n1 && root->data < n2)return root;
		else if(root->data < n1)root = root->right;
		else if(root->data > n2)root = root->left;
	}
	return NULL;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = node->right = NULL;
    return(node);
}

/* Driver program to test mirror() */
int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 8, n2 = 14;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    getchar();
    return 0;
}
