#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/ds.h"


struct list {
	int len;
	int size;
	Item *items; //array of pointers to the items
};

struct listarray {
	int num;
	int size;
	List *lists;
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
int test_listarray(void);
int test_queue(void);
int test_queuearray(void);
int test_stack(void);

#ifdef TESTDS
int main(int argc, char *argv[])
{
	/*test_list();*/
	test_listarray();
	/*test_queue();*/
	//test_stack();
	//test_queuearray();

	return 0;
}

int test_list(void)
{
	int i;
	List list;
	Item item;

	list = create_list(6);
	print_all_list(list);
	add_pos_list(list, (Item) 10, 0);
	add_pos_list(list, (Item) 17, 1);
	add_pos_list(list, (Item) 19, 2);
	add_pos_list(list, (Item) 4, 3);
	add_pos_list(list, (Item) 5, 4);
	add_pos_list(list, (Item) 4, 5);
	i = add_pos_list(list, (Item) 11, 2);
	printf("i=%d\n", i);
	i = add_pos_list(list, (Item) 11, 0);
	printf("i=%d\n", i);
	i = add_pos_list(list, (Item) 11, 9);
	printf("i=%d\n", i);
	print_all_list(list);
	item = remove_pos_list(list, 4);
	printf("item=%ld\n", (long) item);
	print_all_list(list);
	add_pos_list(list, (Item) 7, 0);
	print_all_list(list);
	destroy_list(list);

	return 0;
}

int test_listarray(void)
{
	int i, n;
	List list;
	ListArray listarray;

	listarray = create_listarray(4);
	list = create_list(1);
	add_listarray(listarray, 0, list);
	list = create_list(4);
	add_listarray(listarray, 1, list);
	list = create_list(5);
	add_listarray(listarray, 2, list);
	list = create_list(5);
	add_listarray(listarray, 3, list);
	print_all_listarray(listarray);
	printf("\n");
	n = len_listarray(listarray);
	for (i = 0; i < n; i++) {
		list = get_listarray(listarray, i);
		add_pos_list(list, (Item) i, 0);
	}
	print_all_listarray(listarray);
	printf("\n");
	n = len_listarray(listarray);
	for (i = 0; i < n; i++) {
		list = remove_listarray(listarray, 0);
		destroy_list(list);
	}
	print_all_listarray(listarray);
	destroy_listarray(listarray);

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

	list->len--;
	for (i = pos; i < list->len; i++)
		list->items[i] = list->items[i + 1];

	return temp;
}

int add_pos_list(List list, Item item, int n)
{
	int i;

	if (list->len >= list->size)
		return -1;

	if (n < 0 || n > list->len)
		return -1;

	// make room for the item at the specified position
	for (i = list->len; i > n; i--)
		list->items[i] = list->items[i - 1];

	list->items[n] = item;
	list->len++;

	return 0;
}

Item remove_pos_list(List list, int n)
{
	int i;
	Item item;

	if (n < 0 || n >= list->len)
		return NULL;

	item = list->items[n];
	list->len--;
	for (i = n; i < list->len; i++)
		list->items[i] = list->items[i + 1];

	return item;
}

int clear_list(List list)
{
	list->len = 0;

	return 0;
}

ListArray create_listarray(int size)
{
	ListArray listarray;

	listarray = malloc(sizeof(struct listarray));
	listarray->num = 0;
	listarray->size = size;
	listarray->lists = malloc(size * sizeof(List));

	return listarray;
}

int destroy_listarray(ListArray listarray)
{
	free(listarray->lists);
	free(listarray);

	return 0;
}

int print_listarray(ListArray listarray)
{
	int i;

	printf("listarray=%p:\n", listarray);
	printf("num=%d, size=%d\n", listarray->num, listarray->size);
	for (i = 0; i < listarray->num; i++)
		print_list(listarray->lists[i]);

	return 0;
}

int print_all_listarray(ListArray listarray)
{
	int i;

	printf("listarray=%p:\n", listarray);
	printf("num=%d, size=%d\n", listarray->num, listarray->size);
	for (i = 0; i < listarray->num; i++)
		print_all_list(listarray->lists[i]);

	return 0;
}

int add_listarray(ListArray listarray, int key, List list)
{
	int i;

	if (listarray->num >= listarray->size)
		return -1;

	if (key < 0 || key > listarray->num)
		return -1;

	// make room for the item at the specified position
	for (i = listarray->num; i > key; i--)
		listarray->lists[i] = listarray->lists[i - 1];

	listarray->lists[key] = list;
	listarray->num++;

	return 0;
}

List remove_listarray(ListArray listarray, int key)
{
	int i;
	List list;

	if (key < 0 || key >= listarray->num)
		return NULL;

	list = listarray->lists[key];
	listarray->num--;
	for (i = key; i < listarray->num; i++)
		listarray->lists[i] = listarray->lists[i + 1];

	return list;
}

int len_listarray(ListArray listarray)
{
	return listarray->num;
}

List get_listarray(ListArray listarray, int key)
{
	if (key < 0 || key >= listarray->num)
		return NULL;

	return listarray->lists[key];
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

int num_stack(Stack stack)
{
	return stack->num;
}
