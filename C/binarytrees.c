# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **root, int data ) {
	 if ((*root) == NULL) {
            (*root) = (struct Node*)malloc(sizeof(struct Node));
            (*root)->left = NULL;
            (*root)->right = NULL;
            (*root)->data = data;
	 }
	 else if ((*root)->data > data) {
			insert(&(*root)->left, data);
	 }
	 else if((*root)->data < data){
			insert(&(*root)->right, data);
	 }
}

//int count( node * root ) {
    
//}

//struct Node *delete( node * root , int data ) {
    
//}

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

void postorder(node *root){
    if(root == NULL)return;
	preorder(root->left);
	preorder(root->right);
	printf("%d ", root->data);
}

int main() {
        struct Node *root,*temp;
        root = NULL;
        temp = root;
        int count = 0;
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Inorder\n");
        printf("4. Print Preorder\n");
        printf("5. Print Postorder\n");
        printf("6. Count\n");
        while(1)
        {
                int query;
                scanf("%d",&query);
                if(query==1)
                {
                        int data;
                        scanf("%d",&data);
                        /*if (count == 0) {
							root -> data = data;
							count = 2;
                        }
                        else*/
                        insert(&root, data);
                        //printf("%d\n", root->data);
                }
                /*else if(query==2)
                {
                        int data;
                        scanf("%d",&data);
                        delete(root,data);
                }*/
                else if(query==3)
                {
                        printf("The list is ");
                        inorder(root);
                        printf("\n");
                }
                else if(query==4)
                {
                        printf("The list is ");
                        preorder(root);
                        printf("\n");
                }    
                /*else if(query==5)
                {
                        printf("The list is ");
                        postorder(root);
                        printf("\n");
                }    
                else if(query==6)
                {
                        printf( "%d\n" , count( root ));
                }*/
        }
        getch();
        return 0;
}
