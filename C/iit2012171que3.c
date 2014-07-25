#include <stdio.h>

struct stack {
	int arr[100];
	int i;
};

int size(struct stack * );
void push(struct stack *, int g );
int top(struct stack *);
int is_empty(struct stack *);
int pop(struct stack *);

int main()
{
	char s[25];
	struct stack one;
	int n;

	one.i = 0;

	while (1) {
		scanf("%s", s);

		if (strcmp(s, "exit") == 0) {
			break ;

		} else if (strcmp(s, "push") == 0) {
			scanf("%d\n", &n);
			push(&one, n);
			one.i++;

		} else if (strcmp(s, "size") == 0) {
			printf("%d\n", size(&one));

		} else if (strcmp(s, "is_empty") == 0) {
			if (is_empty(&one) == 1) {
				printf("yes\n");
		        } else {
                                printf("no\n");
                       }

		} else if (strcmp(s, "top") == 0) {
			printf("%d\n", top(&one));

		} else if (strcmp(s, "pop") == 0) {
			if(one.i == 0) {
				printf("Underflow\n");
		        } else {
			        printf("removed %d\n", pop(&one));
			        one.i--;
                        }
		}
	}
	return 0;
}

void push(struct stack *one, int g)
{
one->arr[one->i] = g;

}


int size(struct stack *one)
{
	int m;
	m = one->i;
	return m;
}

int pop(struct stack *one)
{
	return one->arr[one->i - 1];
}

int top(struct stack *one)
{
	return (one->arr[one->i - 1]);
}

int is_empty(struct stack *one)
{
	if (one->i == 0) {
		return 1;
        } else {
        	return 0;
        }

}


