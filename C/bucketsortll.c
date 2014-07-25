#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
	struct node* next;
	int key;
};

void insert(struct node *temp, int key) {
	if(temp->next == NULL) {
		temp->next = (struct node*)malloc(sizeof(struct node));
		//p[n] = p[n]->next;
		//a[n] = (struct node*)malloc(sizeof(struct node*));
		temp->next->key = key;
		//printf("%d 1\n", p[n]->next->key);
		temp->next->next = NULL;
		return;
	}
	else if(temp->next != NULL) {
		while(temp->next != NULL) {
			//p[n] = p[n]->next;
			//printf("%d\n", p[n]->next->key)
			if(temp->next->key >= key) {
				struct node* temp1;
				temp1 = temp->next;
				temp->next = (struct node*)malloc(sizeof(struct node*));
				//p[n] = p[n]->next;
				temp->next->key = key;
				temp->next->next = temp1;
				//printf("%d 2\n", p[n]->next->key);
				return;
			}
			temp = temp->next;
		}
		//printf("%d        ", p[n]->key);
		temp->next = (struct node*)malloc(sizeof(struct node*));
		temp = temp->next;
		temp->key = key;
		temp->next = NULL;
		//printf("%d 3\n", p[n]->key);
		//print(p);
		return;
	}
}

void print(struct node *p1[10]) {
	int i;
	struct node* temp;
	for(i = 0; i < 10; i++) {
		temp = p1[i];
		while(temp->next != NULL) {
			temp = temp->next;
			printf("%d ", temp->key);
		}
	}
	return;
}

int main() {
	int i;
	struct node* a[10], *temp;
	for(i = 0; i < 10; i++) {
        a[i] = (struct node*)malloc(sizeof(struct node*));
        temp = a[i];
        temp->next = NULL;
	}
	int arr[10] = {45, 76, 62, 63, 66, 25, 99, 65, 89, 02};
	for(i = 0; i < 10; i++) {
		int n = arr[i]/10;
		insert(a[n], arr[i]);
	}
	//printf("%d\n\n", a[6]->next->next->key);
	print(a);
	getch();
	return 0;
}
