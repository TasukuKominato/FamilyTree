#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	char name[100];
	int birthday;
	struct _node *spouse;
	struct _node *father;
	struct _node *mother;
	struct _node *child1;
	struct _node *child2;
	struct _node *child3;
	struct _node *child4;
	struct _node *child5;
} node;

node *search(node *head, char name[]) {
	node *p = head;
	return p;
}

int add(node *head, node *new) {

	return 0;
}

int delete(node *head, char name[]) {
	node *p = head;
	return 0;
}

void display(node *head) {
	return;
}

int main(void) {
	return 0;
}