#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	struct node *left;
	struct node *right;
	char a;
	int b;
};

void insert(struct node *root) {
	root->left = (struct node *)malloc(sizeof(struct node));
	root->right = (struct node *)malloc(sizeof(struct node));
	root->left->b = 0;
	root->right->b = 1;
	root->left->a = 'x';
	struct node *temp;
	temp = root->left;
	temp->left = NULL;
	temp->right = NULL;
	temp = root->right;
	temp->left = (struct node *)malloc(sizeof(struct node));
	temp->right = (struct node *)malloc(sizeof(struct node));
    temp->left->b = 0;
	temp->right->b = 1;
    temp->left->a = 'y';
	temp->right->a = 'z';
	temp->left->left = NULL;
	temp->left->right = NULL;
    temp->right->left = NULL;
	temp->right->right = NULL;
}

void decode(char s[10], struct node *root) {
	struct node *temp;
	temp = root;
	int i = 0;
	while(s[i] != '\0') {
		if(s[i] == '0') {
			temp = temp->left;
		}
		else if(s[i] == '1') {
			temp = temp->right;
		}
		if(temp->a == 'x' || temp->a == 'y' || temp->a == 'z') {
			printf("%c", temp->a);
			temp = root;
			i++;
		}
		else {
			i++;
		}
	}
}

int main() {
	struct node *root;
	root = (struct node *)malloc(sizeof(struct node));
	root->left = NULL;
	root->right = NULL;
	insert(root);  //x = 0, y = 10, z = 11;
	char s[10];
	scanf("%s", s);
	decode(s, root);
	//printf("%c", root->right->right->a);
	getch();
	return 0;

}
