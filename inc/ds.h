#ifndef DS_H
#define DS_H

typedef void *Item;

typedef struct dgraph *DGraph;
typedef struct dict *Dict;
typedef struct list *List;
typedef struct queue *Queue;
typedef struct stack *Stack;

List *create_list(void);
int destroy_list(List **list);
int print_list(List *list);
int len_list(List *list);
int enqueue_list(List *list, Item item);
Item dequeue_list(List *list);
int push_list(List *list, Item item);
Item pop_list(List *list);
int add_list(List *list, Item item, int pos);
Item remove_list(List *list, int pos);
int shuffle_list(List *list);
Item peak_list(List *list, int pos);
int contains_list(List *list, Item item);
int iterate_list(List *list);
Item next_list(List *list);

Dict *create_dict(int tot);
int destroy_dict(Dict *dict);
int print_dict(Dict *dict);
int add_dict(Dict *dict, Item item, int key);
Item remove_dict(Dict *dict, int key);
Item contains_dict(Dict *dict, int key);

Queue create_queue(int size);
int destroy_queue(Queue queue);
int print_queue(Queue queue);
int print_queue_all(Queue queue);
int add_queue(Queue queue, Item item);
Item remove_queue(Queue queue);

Stack create_stack(int size);
int destroy_stack(Stack stack);
int print_stack(Stack stack);
int print_stack_all(Stack stack);
int add_stack(Stack stack, Item item);
Item remove_stack(Stack stack);
#endif //DS_H
