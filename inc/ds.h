/* Generic Data Structure Library */

#ifndef DS_H
#define DS_H

typedef void *Addr;
typedef struct list List;
typedef struct dict Dict;

List *create_list(void);
int destroy_list(List **list);
int print_list(List *list);
int len_list(List *list);
int enqueue_list(List *list, Addr item);
Addr dequeue_list(List *list);
int push_list(List *list, Addr item);
Addr pop_list(List *list);
int add_list(List *list, Addr item, int pos);
Addr remove_list(List *list, int pos);
int shuffle_list(List *list);
Addr peak_list(List *list, int pos);
int contains_list(List *list, Addr item);
int iterate_list(List *list);
Addr next_list(List *list);

Dict *create_dict(int tot);
int destroy_dict(Dict *dict);
int print_dict(Dict *dict);
int add_dict(Dict *dict, Addr item, int key);
Addr remove_dict(Dict *dict, int key);
Addr contains_dict(Dict *dict, int key);

#endif //DS_H
