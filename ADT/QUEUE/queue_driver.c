/* File: driver_queue.c */
/* *** Driver ABSTRACT DATA TYPE QUEUE *** */

#include <stdio.h>
#include "queue.h"

int main() {
    /* KAMUS */
    Barang pp1, pp2, pp3, ppTemp;
    Queue q;

    /* ALGORITMA*/
    // Membuat Queue kosong
    CreateQueue(&q);
    printf("Queue setelah dibentuk:\n");
    displayQueue(q);
    printf("\n");

    // Cek apakah Queue kosong
    printf("Apakah Queue kosong?");
    if (isEmptyQ(q)) {
        printf("Queue kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }
    printf("Banyaknya elemen Queue: %d\n", lengthQ(q));
    printf("\n");

    // Simulasi enqueue berdasarkan prioritas waktu masuk
    printf("Enqueue 1: \n");
    enqueue(&q, pp1);
    displayQueue(q);
    printf("\n");

    // pp2 seharusnya masuk ke urutan depan karena waktu masuknya lebih kecil dari pp1
    printf("Enqueue 2: \n");
    enqueue(&q, pp2);
    displayQueue(q);
    printf("\n");

    printf("Enqueue 3: \n");
    enqueue(&q, pp3);
    displayQueue(q);
    printf("\n");

    // Cek apakah Queue kosong
    printf("Apakah Queue kosong?");
    if (isEmptyQ(q)) {
        printf("Queue kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }
    printf("\n");

    // Cek apakah Queue penuh
    if (isFullQ(q)) {
        printf("Queue penuh\n");
    } else {
        printf("Queue tidak penuh\n");
    }
    printf("Banyaknya elemen Queue: %d\n", lengthQ(q));
    printf("\n");

    // Simulasi dequeue
    printf("Dequeue 1: \n");
    dequeue(&q, &ppTemp);
    displayQueue(q);
    printf("\n");

    printf("Dequeue 2: \n");
    dequeue(&q, &ppTemp);
    displayQueue(q);
    printf("\n");

    // Cek apakah Queue kosong
    printf("Apakah Queue kosong?");
    if (isEmptyQ(q)) {
        printf("Queue kosong\n");
    } else {
        printf("Queue tidak kosong\n");
    }
    printf("Banyaknya elemen Queue: %d\n", lengthQ(q));
    printf("\n");

    float exeKiller;
    printf("\n\n(End of Program - Enter non-whitespace character to exit)");
    scanf("%f", &exeKiller); 
    /* for executable file */
    
    return 0;
}