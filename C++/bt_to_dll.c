#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node{
	struct node *left;
	struct node *right;
	int data;
};

struct node *input(struct node *root, int data){
    root = (struct node*)malloc(sizeof(struct node));
    (root)->right = NULL;
    root->left = NULL;
    root->data = data;
    //printf("%d\n", root);
    return root;
}
struct node* prev = NULL;
void convert(struct node *root, struct node **head){
	if(root == NULL)return;
	//static struct node* prev = NULL;
	convert(root->left, head);
	if(prev == NULL)*head = root;
	else{
		prev->right = root;
		root->left = prev;
	}
	prev = root;
	convert(root->right, head);
}
void print(struct node *root)
{
    while (root!=NULL)
    {
        printf("%d ", root->data);
        root = root->right;
    }
}

int main(){
	struct node *root = NULL;
    root = input(root, 10);
    root->left = input((root->left), 12);
    root->right = input((root->right), 15);
    root->left->left = input((root->left->left), 25);
    root->left->right = input((root->left->right), 30);
    root->right->left = input((root->right->left), 36);
	//printf("%d", root->left->right->data);
	struct node *head = NULL;
	convert(root, &head);
	print(head);
	getch();
	return 0;
}
