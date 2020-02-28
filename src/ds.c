#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/ds.h"


struct list {
	int len;
	int size;
	Item *items; //array of pointers to the items
};

struct queue {
	int num;
	int size;
	int front;
	int back;
	Item *items; //array of pointers to the items
};

struct queuearray {
	int num;
	int size;
	Queue *queues;
};

struct stack {
	int num;
	int size;
	int top;
	Item *items; //array of pointers to the items
};

int test_list(void);
int test_queue(void);
int test_queuearray(void);
int test_stack(void);

#ifdef TESTDS
int main(int argc, char *argv[])
{
	/*test_list();*/
	/*test_queue();*/
	test_stack();
	//test_queuearray();

	return 0;
}

int test_list(void)
{
	int i;
	List list;
	Item item;

	list = create_list(20);
	print_all_list(list);
	for (i = 0; i < 22; i++)
		add_list(list, (Item) i + 1);
	print_all_list(list);
	printf("%d\n", len_list(list));
	printf("%p\n", peak_list(list, -1));
	printf("%p\n", peak_list(list, 100));
	printf("%p\n", peak_list(list, 10));
	print_all_list(list);
	remove_list(list, (Item) 8);
	remove_list(list, (Item) 11);
	remove_list(list, (Item) 110);
	print_all_list(list);
	add_list(list, (Item) 112);
	print_all_list(list);
	clear_list(list);
	print_all_list(list);
	printf("%p\n", peak_list(list, -1));
	printf("%p\n", peak_list(list, 100));
	item = remove_list(list, (Item) 8);
	printf("item is %p\n", item);
	add_list(list, (Item) 5);
	add_list(list, (Item) 7);
	print_all_list(list);
	destroy_list(list);

	return 0;
}

int test_queue(void)
{
	Queue queue;

	queue = create_queue(7);
	add_queue(queue, (Item) 1);
	add_queue(queue, (Item) 2);
	add_queue(queue, (Item) 3);
	add_queue(queue, (Item) 4);
	add_queue(queue, (Item) 5);
	add_queue(queue, (Item) 6);
	add_queue(queue, (Item) 7);
	print_all_queue(queue);
	shuffle_queue(queue);
	print_all_queue(queue);
	remove_queue(queue);
	remove_queue(queue);
	print_all_queue(queue);
	shuffle_queue(queue);
	print_all_queue(queue);
	remove_queue(queue);
	print_all_queue(queue);
	add_queue(queue, (Item) 33);
	print_all_queue(queue);
	destroy_queue(queue);

	return 0;
}

int test_queuearray(void)
{
	int queue_sizes[5];
	QueueArray queuearray;
	Item item;

	queue_sizes[0] = 1;
	queue_sizes[1] = 6;
	queue_sizes[2] = 4;
	queue_sizes[3] = 5;
	queue_sizes[4] = 5;
	queuearray = create_queuearray(5, queue_sizes);
	print_all_queuearray(queuearray);
	printf("%d\n", add_queuearray(queuearray, 0, (Item) 9));
	printf("%d\n", add_queuearray(queuearray, 0, (Item) 9));
	print_all_queuearray(queuearray);
	item = remove_queuearray(queuearray, 0);
	printf("%ld\n", (long) item);
	print_all_queuearray(queuearray);
	printf("%d\n", add_queuearray(queuearray, 1, (Item) 8));
	printf("%d\n", add_queuearray(queuearray, 2, (Item) 9));
	print_all_queuearray(queuearray);
	destroy_queuearray(queuearray);

	return 0;
}

int test_stack(void)
{
	Stack stack;

	stack = create_stack(5);
	print_all_stack(stack);
	add_stack(stack, (Item) 1);
	add_stack(stack, (Item) 2);
	add_stack(stack, (Item) 3);
	add_stack(stack, (Item) 4);
	add_stack(stack, (Item) 5);
	print_all_stack(stack);
	printf("peak stack %d is %p\n", 2, peak_stack(stack, 2));
	printf("peak stack %d is %p\n", 1, peak_stack(stack, 1));
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	print_all_stack(stack);
	add_stack(stack, (Item) 9);
	add_stack(stack, (Item) 9);
	print_all_stack(stack);
	remove_stack(stack);
	print_all_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	remove_stack(stack);
	print_all_stack(stack);
	add_stack(stack, (Item) 8);
	print_all_stack(stack);
	destroy_stack(stack);

	return 0;
}
#endif

List create_list(int size)
{
	List list;

	list = malloc(sizeof(struct list));
	list->len = 0;
	list->size = size;
	list->items = malloc(size * sizeof(Item));

	return list;
}

int destroy_list(List list)
{
	free(list->items);
	free(list);

	return 0;
}

int print_list(List list)
{
	printf("list=%p:\n", list);
	printf("len=%d, size=%d\n", list->len, list->size);

	return 0;
}

int print_all_list(List list)
{
	int i;
	Item item;

	print_list(list);
	for (i = 0; i < list->len; i++) {
		item = list->items[i];
		if (i == 0)
			printf("%p", item);
		else
			printf(", %p", item);
	}
	if (list->len)
		printf("\n");

	return 0;
}

int len_list(List list)
{
	return list->len;
}

Item peak_list(List list, int n)
{
	if (n < 0 || n >= list->len)
		return NULL;

	return list->items[n];
}

int add_list(List list, Item item)
{
	if (list->len >= list->size)
		return -1;

	list->items[list->len] = item;
	list->len++;

	return 0;
}

Item remove_list(List list, Item item)
{
	int i, pos;
	Item temp;

	if (list->len <= 0)
		return NULL;

	pos = -1;
	temp = NULL;
	for (i = 0; i < list->len; i++) {
		if (list->items[i] == item) {
			pos = i;
			temp = list->items[i];
			break;
		}
	}

	if (pos == -1)
		return NULL;

	for (i = pos; i < list->len - 1; i++)
		list->items[i] = list->items[i + 1];
	list->len--;

	return temp;
}

int clear_list(List list)
{
	list->len = 0;

	return 0;
}

QueueArray create_queuearray(int size, int queue_sizes[])
{
	int i;
	QueueArray queuearray;

	queuearray = malloc(sizeof(struct queuearray));
	queuearray->num = 0;
	queuearray->size = size;
	queuearray->queues = malloc(size * sizeof(Queue));
	for (i = 0; i < size; i++)
		queuearray->queues[i] = create_queue(queue_sizes[i]);

	return queuearray;
}

int destroy_queuearray(QueueArray queuearray)
{
	int i;

	for (i = 0; i < queuearray->size; i++)
		destroy_queue(queuearray->queues[i]);

	free(queuearray->queues);
	free(queuearray);

	return 0;
}

int print_queuearray(QueueArray queuearray)
{
	int i;

	printf("queuearray=%p:\n", queuearray);
	printf("num=%d, size=%d\n", queuearray->num, queuearray->size);
	for (i = 0; i < queuearray->size; i++)
		print_queue(queuearray->queues[i]);

	return 0;
}

int print_all_queuearray(QueueArray queuearray)
{
	int i;

	printf("queuearray=%p:\n", queuearray);
	printf("num=%d, size=%d\n", queuearray->num, queuearray->size);
	for (i = 0; i < queuearray->size; i++)
		print_all_queue(queuearray->queues[i]);

	return 0;
}

int add_queuearray(QueueArray queuearray, int key, Item item)
{
	int i;

	if (key < 0 || key >= queuearray->size)
		return -1;

	if ((i = add_queue(queuearray->queues[key], item)) == 0)
		queuearray->num++;

	return i;
}

Item remove_queuearray(QueueArray queuearray, int key)
{
	Item item;

	if (key < 0 || key >= queuearray->size)
		return NULL;

	if ((item = remove_queue(queuearray->queues[key])) != NULL);
		queuearray->num--;

	return item;
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

int print_all_queue(Queue queue)
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

int shuffle_queue(Queue queue)
{
	int i, j, k;
	Item item;

	for (i = 0; i < queue->num; i++) {
		j = (queue->front + i) % queue->size;
		k = (queue->front + i + (rand() % (queue->num - i))) % queue->size;
		item = queue->items[j];
		queue->items[j] = queue->items[k];
		queue->items[k] = item;
	}

	return 0;
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

int print_all_stack(Stack stack)
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

Item peak_stack(Stack stack, int n)
{
	if (n < 0 || n >= stack->num)
		return NULL;

	return stack->items[stack->top - n - 1];
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
