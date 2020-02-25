#include <stdio.h>
#include <stdlib.h>
#include "../inc/ds.h"


typedef struct node Node;

struct node {
	Item *item;
	Node *next;
};
	
struct list {
	int len;
	Node *head;
};

/*static Node *add_node(List *list, int pos);*/

struct queue {
	int num;
	int size;
	int front;
	int back;
	Item *items; //array of pointers to the items
};

struct stack {
	int num;
	int size;
	int top;
	Item *items; //array of pointers to the items
};

int test_queue(void);
int test_stack(void);

#ifdef TESTDS
int main(int argc, char *argv[])
{
	test_queue();
	test_stack();

	return 0;
}
#endif

int test_queue(void)
{
	int i;
	Queue queue;
	Item item;

	queue = create_queue(7);
	print_queue_all(queue);
	item = remove_queue(queue);
	printf("%p\n", item);
	add_queue(queue, (Item) 4);
	add_queue(queue, (Item) 2);
	add_queue(queue, (Item) 7);
	add_queue(queue, (Item) 11);
	add_queue(queue, (Item) 10);
	add_queue(queue, (Item) 1);
	add_queue(queue, (Item) 4);
	i = add_queue(queue, (Item) 5);
	printf("%d\n", i);
	print_queue_all(queue);
	remove_queue(queue);
	remove_queue(queue);
	remove_queue(queue);
	remove_queue(queue);
	print_queue_all(queue);
	add_queue(queue, (Item) 100);
	print_queue_all(queue);
	item = remove_queue(queue);
	print_queue_all(queue);
	destroy_queue(queue);
	printf("%ld\n", (long) item);

	return 0;
}

int test_stack(void)
{
	Stack stack;

	stack = create_stack(5);
	print_stack_all(stack);
	add_stack(stack, (Item) 1);
	add_stack(stack, (Item) 2);
	add_stack(stack, (Item) 3);
	add_stack(stack, (Item) 4);
	add_stack(stack, (Item) 5);
	print_stack_all(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	print_stack_all(stack);
	add_stack(stack, (Item) 9);
	add_stack(stack, (Item) 9);
	print_stack_all(stack);
	remove_stack(stack);
	print_stack_all(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	print_stack_all(stack);
	add_stack(stack, (Item) 8);
	print_stack_all(stack);
	destroy_stack(stack);

	return 0;
}

Queue create_queue(int size)
{
	Queue queue;

	queue = malloc(sizeof(struct queue));
	queue->num = 0;
	queue->size = size;
	queue->front = 0;
	queue->back = 0;
	queue->items = malloc(size * sizeof(Item));

	return queue;
}

int destroy_queue(Queue queue)
{
	free(queue->items);
	free(queue);

	return 0;
}

int print_queue(Queue queue)
{
	printf("queue=%p:\n", queue);
	printf("num=%d, size=%d, front=%d, back=%d\n", queue->num,
			queue->size, queue->front, queue->back);

	return 0;
}

int print_queue_all(Queue queue)
{
	int i;
	Item item;

	print_queue(queue);
	for (i = 0; i < queue->num; i++) {
		item = *(queue->items + ((queue->front + i) % queue->size));
		if (!i)
			printf("%p", item);
		else
			printf(", %p", item);
	}
	if (queue->num)
		printf("\n");

	return 0;
}

int add_queue(Queue queue, Item item)
{
	if (queue->num >= queue->size)
		return -1;

	*(queue->items + queue->back) = item;
	queue->back = (queue->back + 1) % queue->size;
	queue->num++;

	return 0;
}

Item remove_queue(Queue queue)
{
	Item item;

	if (queue->num <= 0)
		return NULL;

	item = *(queue->items + queue->front);
	queue->front = (queue->front + 1) % queue->size;
	queue->num--;

	return item;
}

Stack create_stack(int size)
{
	Stack stack;

	stack = malloc(sizeof(struct stack));
	stack->num = 0;
	stack->size = size;
	stack->top = 0;
	stack->items = malloc(size * sizeof(Item));

	return stack;
}

int destroy_stack(Stack stack)
{
	free(stack->items);
	free(stack);

	return 0;
}

int print_stack(Stack stack)
{
	printf("stack=%p:\n", stack);
	printf("num=%d, size=%d, top=%d\n", stack->num, stack->size, stack->top);

	return 0;
}

int print_stack_all(Stack stack)
{
	int i;
	Item item;

	print_stack(stack);
	for (i = 0; i < stack->num; i++) {
		item = *(stack->items + i);
		if (!i)
			printf("%p", item);
		else
			printf(", %p", item);
	}
	if (stack->num)
		printf("\n");

	return 0;
}

int add_stack(Stack stack, Item item)
{
	if (stack->num >= stack->size)
		return -1;

	*(stack->items + stack->top) = item;
	stack->top++;
	stack->num++;

	return 0;
}

Item remove_stack(Stack stack)
{
	Item item;

	if (stack->num <= 0)
		return NULL;

	item = *(stack->items + stack->top - 1);
	stack->top--;
	stack->num--;

	return item;
}

/*List *create_list(void)*/
/*{*/
	/*List *list;*/

	/*if ((list = malloc(sizeof(List))) == NULL)*/
		/*return NULL;*/

	/*list->len = 0;*/
	/*list->head = NULL;*/

	/*return list;*/
/*}*/

/*int destroy_list(List **list_ptr)*/
/*{*/
	/*List *list;*/
	/*Node *node;*/

	/*if (*list_ptr == NULL)*/
		/*return 0;*/

	/*list = *list_ptr;*/

	/*while (list->head != NULL) {*/
		/*node = list->head;*/
		/*list->head = list->head->next;*/
		/*free(node);*/
	/*}*/

	/*free(list);*/
	/**list_ptr = NULL;*/

	/*return 0;*/
/*}*/

/*int print_list(List *list)*/
/*{*/
	/*int i;*/
	/*Node *node;*/

	/*if (list == NULL) {*/
		/*printf("list: NULL\n");*/
		/*return 0;*/
	/*}*/

	/*printf("list=%p:\n", list);*/
	/*printf("len=%d, head=%p\n", list->len, list->head);*/

	/*node = list->head;*/
	/*for (i = 0; i < list->len; i++) {*/
		/*printf("node %d: item=%p\n", i, node->item);*/
		/*node = node->next;*/
	/*}*/

	/*return 0;*/
/*}*/

/*int len_list(List *list)*/
/*{*/
	/*if (list == NULL)*/
		/*return -1;*/

	/*return list->len;*/
/*}*/


/*int enqueue_list(List *list, Addr item)*/
/*{*/
	/*Node *node;*/

	/*if ((node = add_node(list, list->len)) == NULL)*/
		/*return -1;*/

	/*node->item = item;*/

	/*return 0;*/
/*}*/

/*static Node *add_node(List *list, int pos)*/
/*{*/
	/*Node *node, *prev, *next;*/
	/*int i;*/

	/*if (pos < 0 || pos > list->len)*/
		/*return NULL;*/

	/*if ((node = malloc(sizeof(Node))) == NULL)*/
		/*return NULL;*/
	/*node->next = NULL; */

	/*prev = NULL;*/
	/*next = list->head;*/
	/*for (i = 0; i < pos; i++) {*/
		/*prev = next;*/
		/*next = next->next;*/
	/*}*/
	
	/*if (prev == NULL && next == NULL)*/
		/*list->head = node;*/
	/*else if (prev == NULL && next != NULL) {*/
		/*node->next = next;*/
		/*list->head = node;*/
	/*} else if (prev != NULL && next == NULL)*/
		/*prev->next = node;*/
	/*else {*/
		/*node->next = next;*/
		/*prev-> next = node;*/
	/*}*/

	/*list->len++;*/

	/*return node;*/
/*}*/
