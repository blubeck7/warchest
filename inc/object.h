#ifndef OBJECT_H
#define OBJECT_H

typedef struct object *Object;
struct object {
	Object (*create)(...);

#endif //OBJECT_H
