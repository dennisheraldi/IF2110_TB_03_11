#include "list_linked.h"
#include <stdio.h>

int list_linked_driver(){
    Barang barang1,barang2;
    //Assign nilai tiap elemen barang1 dan barang2 disini bila ingin menggunakan driver
    ListLinked list_linked;
    CreateListLinked(&list_linked);
    if (isEmpty(list_linked)) {
        printf("List kosong !");
    }
    insertLast(&list_linked,barang1);
    insertFirst(&list_linked,barang2);
    printf("Saat ini panjang list_linked adalah: %d", length(list_linked));
    printf("Barang 1 ditemukan di indeks ke : %d", indexOf(list_linked,barang1));
}
