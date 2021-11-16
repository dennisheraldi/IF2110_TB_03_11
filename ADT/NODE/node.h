#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "barang.h"

typedef int ElType;
typedef struct node* Address;
typedef struct node {
    Barang info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(Barang val);


#endif