# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
#include <stack>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void insertdp(struct Node **root, int data ) {
	 if ((*root) == NULL) {
            (*root) = (struct Node*)malloc(sizeof(struct Node));
            (*root)->left = NULL;
            (*root)->right = NULL;
            (*root)->data = data;
	 }
	 else if ((*root)->data > data) {
			insertdp(&(*root)->left, data);
	 }
	 else if((*root)->data < data){
			insertdp(&(*root)->right, data);
	 }
}

struct Node* insertsp(struct Node *root, int data){
    if ((root) == NULL) {
            (root) = (struct Node*)malloc(sizeof(struct Node));
            (root)->left = NULL;
            (root)->right = NULL;
            (root)->data = data;
            return root;
	 }
	 else if ((root)->data > data) {
			root->left = insertsp((root)->left, data);
	 }
	 else if((root)->data < data){
			root->right = insertsp((root)->right, data);
	 }
	 return root;
}

int countn(struct Node* root, int n) {
    if(root == NULL)return n;
	n = countn(root->left, n);
	n++;
    n = countn(root->right, n);
}

struct Node* deleten(struct Node* root, int data) {
	struct Node *temp;
	if(root == NULL){
		printf("Data not found\n");
	}
    if(root->data == data){
		if(root->left == NULL && root->right == NULL){
			temp = root;
			root = NULL;
			free(temp);
   			return root;
		}
		else if(root->left == NULL){
			temp = root;
			root = root->right;
			free(temp);
			return root;
		}
		else if(root->right == NULL){
			temp = root;
			root = root->left;
			free(temp);
			return root;
		}
		else {
			temp = root->left;
			while(temp->right != NULL){
				temp = temp->right;
			}
			root->data = temp->data;
			root->left = deleten(root->left, temp->data);
			return root;
		}
	}
	else if(data > root->data)root->right = deleten(root->right, data);
    else if(data < root->data)root->left = deleten(root->left, data);
    return root;
}

void inorder(struct Node *root)
{
	if(root == NULL)return;
	inorder(root->left);
	printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root){
	if(root == NULL)return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL)return;
	preorder(root->left);
	preorder(root->right);
	printf("%d ", root->data);
}

void zigzagorder(struct Node *root){
	stack <struct Node *> current, next;
	current.push(root);
	bool ltr = true;
	while(!current.empty()){
		root = current.top();
		current.pop();
		printf("%d ", root->data);
		if(root){
			if(ltr){
				if(root->left != NULL)
				next.push(root->left);
				if(root->right != NULL)
				next.push(root->right);
			}
			else{
                if(root->right != NULL)
	            next.push(root->right);
	            if(root->left != NULL)
	            next.push(root->left);
			}
		}
		if(current.empty()){
			ltr  = !ltr;
			swap(current, next);
		}
	}
}

int main() {
        struct Node *root;
        root = NULL;
        int count = 0;
        printf("1. Insertdp\n");
        printf("2. Delete\n");
        printf("3. Print Inorder\n");
        printf("4. Print Preorder\n");
        printf("5. Print Postorder\n");
        printf("6. Count\n");
        printf("7. Print ZigZagorder\n");
        printf("8. Insertsp\n");
        while(1)
        {
                int query;
                scanf("%d",&query);
                if(query == 1)
                {
                        int data;
                        scanf("%d",&data);
                        insertdp(&root, data);
                }
                else if(query == 2)
                {
                        int data;
                        scanf("%d", &data);
                        root = deleten(root, data);
                }
                else if(query == 3)
                {
                        printf("The list is ");
                        inorder(root);
                        printf("\n");
                }
                else if(query == 4)
                {
                        printf("The list is ");
                        preorder(root);
                        printf("\n");
                }    
                else if(query == 5)
                {
                        printf("The list is ");
                        postorder(root);
                        printf("\n");
                }    
                else if(query == 6)
                {
                    printf("%d\n", countn(root, 0));
                }
                else if(query == 7)
                {
                        printf("The list is ");
                        zigzagorder(root);
                        printf("\n");
                }
                else if(query == 8)
                {
                        int data;
                        scanf("%d",&data);
                        root = insertsp(root, data);
                }
        }
        getch();
        return 0;
}
