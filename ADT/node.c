/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>

Address newNode(Barang val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}