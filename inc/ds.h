#ifndef DS_H
#define DS_H

typedef void *Item;

//typedef struct dgraph *DGraph;
typedef struct list *List;
typedef struct queue *Queue;
typedef struct queuearray *QueueArray;
typedef struct stack *Stack;

List create_list(int size);
int destroy_list(List list);
int print_list(List list);
int print_all_list(List list);
int len_list(List list);
Item peak_list(List list, int n);
int add_list(List list, Item item);
Item remove_list(List list, Item item);
int clear_list(List list);
//int contains_list(List *list, Item item);
//int iterate_list(List *list);
//Item next_list(List *list);

Queue create_queue(int size);
int destroy_queue(Queue queue);
int print_queue(Queue queue);
int print_all_queue(Queue queue);
int add_queue(Queue queue, Item item);
Item remove_queue(Queue queue);
int shuffle_queue(Queue queue);

QueueArray create_queuearray(int size, int queue_sizes[]);
int destroy_queuearray(QueueArray queuearray);
int print_queuearray(QueueArray queuearray);
int print_all_queuearray(QueueArray queuearray);
int add_queuearray(QueueArray queuearray, int key, Item item);
Item remove_queuearray(QueueArray queuearray, int key);

Stack create_stack(int size);
int destroy_stack(Stack stack);
int print_stack(Stack stack);
int print_all_stack(Stack stack);
int add_stack(Stack stack, Item item);
Item remove_stack(Stack stack);
Item peak_stack(Stack stack, int n);
#endif //DS_H
