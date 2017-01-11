#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int val;
	struct _node *prev;
	struct _node *next;
} node;

int put(node *head, int val) {
	node *new;
	new = (node *)malloc(sizeof(node));
	if(new == NULL) return -1;
	new->val = val;

	new->next = head->next;
	new->prev = head;
	if(head->next != NULL) (head->next)->prev = new;
	head->next = new;
	return 0;
}

int get(node *head) {
	node *p = head;
	int result = -1;
	if(head->next != NULL) {
		while(p->next != NULL) p = p->next;
		result = p->val;
		(p->prev)->next = NULL;
		free(p);
	}
	return result;
}

int delete(node *head, int val) {
	node *p = head;
	int result = -1;
	while(p->val != val && p->next != NULL) p = p->next;
	if(p->val == val) {
		result = val;
		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;
		free(p);
	}
	return result;
}

void display(node *head) {
	printf("queue:");
	node *p = head;
	while(p->next != NULL) {
		p = p->next;
	}
	while(p->val != -1){
		printf(" %d", p->val);
		p = p->prev;
	}
	printf("\n");
	return;
}

int main(void) {
	node head = {-1, NULL, NULL};
	int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, res;
	
	/* 要素なしではgetできない */
	res = get(&head);
	printf("get %d\n", res);
	
	/* 要素なしではdeleteできない */
	res = delete(&head, 7);
	printf("delete %d\n", res);

	/* 要素なしでは何もdisplayされない */
	display(&head);

	/* 0~9を順にput */
	for(i = 0; i < 10; i++) {
		printf("put %d\n", nums[i]);
		res = put(&head, nums[i]);
		if(res != 0) return 1;
	}

	/* 0 1 2 3 4 5 6 7 8 9をdisplay */
	display(&head);

	/* 3回get */
	for(i = 0; i < 3; i++) {
		res = get(&head);
		printf("get %d\n", res);
	}

	/* 3 4 5 6 7 8 9をdisplay */
	display(&head);

	/* 要素7をdelete */
	res = delete(&head, 7);
	printf("delete %d\n", res);

	/* 3 4 5 6 8 9をdisplay */
	display(&head);

	/* 要素7はもうないのでdeleteできない */
	res = delete(&head, 7);
	printf("delete %d\n", res);
	return 0;
}