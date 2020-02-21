#include <stdio.h>
#include <stdlib.h>
#include "../inc/ds.h"


typedef struct node Node;

struct node {
	Addr *item;
	Node *next;
};
	
struct list {
	int len;
	Node *head;
};

static Node *add_node(List *list, int pos);

int main(int argc, char *argv[])
{
	List *list;
	int n, m, p;

	list = create_list();
	n = 4;
	m = 7;
	p = 9;
	enqueue_list(list, (Addr) n);
	enqueue_list(list, (Addr) m);
	enqueue_list(list, (Addr) p);
	print_list(list);
	destroy_list(&list);

	return 0;
}

List *create_list(void)
{
	List *list;

	if ((list = malloc(sizeof(List))) == NULL)
		return NULL;

	list->len = 0;
	list->head = NULL;

	return list;
}

int destroy_list(List **list_ptr)
{
	List *list;
	Node *node;

	if (*list_ptr == NULL)
		return 0;

	list = *list_ptr;

	while (list->head != NULL) {
		node = list->head;
		list->head = list->head->next;
		free(node);
	}

	free(list);
	*list_ptr = NULL;

	return 0;
}

int print_list(List *list)
{
	int i;
	Node *node;

	if (list == NULL) {
		printf("list: NULL\n");
		return 0;
	}

	printf("list=%p:\n", list);
	printf("len=%d, head=%p\n", list->len, list->head);

	node = list->head;
	for (i = 0; i < list->len; i++) {
		printf("node %d: item=%p\n", i, node->item);
		node = node->next;
	}

	return 0;
}

int len_list(List *list)
{
	if (list == NULL)
		return -1;

	return list->len;
}


int enqueue_list(List *list, Addr item)
{
	Node *node;

	if ((node = add_node(list, list->len)) == NULL)
		return -1;

	node->item = item;

	return 0;
}

static Node *add_node(List *list, int pos)
{
	Node *node, *prev, *next;
	int i;

	if (pos < 0 || pos > list->len)
		return NULL;

	if ((node = malloc(sizeof(Node))) == NULL)
		return NULL;
	node->next = NULL; 

	prev = NULL;
	next = list->head;
	for (i = 0; i < pos; i++) {
		prev = next;
		next = next->next;
	}
	
	if (prev == NULL && next == NULL)
		list->head = node;
	else if (prev == NULL && next != NULL) {
		node->next = next;
		list->head = node;
	} else if (prev != NULL && next == NULL)
		prev->next = node;
	else {
		node->next = next;
		prev-> next = node;
	}

	list->len++;

	return node;
}
