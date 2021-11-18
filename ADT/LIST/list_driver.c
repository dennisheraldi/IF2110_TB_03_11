#include "list.c"
#include <stdio.h>
/* DRIVER ADT LIST STATIS TIDAK TERURUT */
int main() {
    List l;
    int val;
    CreateListLS(&l);
    // readListLS(&l);
    // printf("\n");
    displayListLS(l); printf("\n");

    insertElmt(&l, 2); displayListLS(l); printf("\n");
    insertElmt(&l, 3); displayListLS(l); printf("\n");
    insertElmt(&l, 1); displayListLS(l); printf("\n");
    insertElmt(&l, 5); displayListLS(l); printf("\n");
    insertElmt(&l, 1); displayListLS(l); printf("\n");
    
    deleteElmt(&l, 2); displayListLS(l); printf("\n");
    deleteElmt(&l, 4); displayListLS(l); printf("\n");
    deleteElmt(&l, 1); displayListLS(l); printf("\n");
    deleteElmt(&l, 3); displayListLS(l); printf("\n");
    insertElmt(&l, 5); displayListLS(l); printf("\n");
    insertElmt(&l, 3); displayListLS(l); printf("\n");
    // deleteAtLS(&l, 1, &val);
    // printf("\n");
    // displayListLS(l);
}