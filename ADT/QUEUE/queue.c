#include <stdio.h>
#include "queue.h"

/*
Nama: David Karel Halomoan
NIM: 13520154
Tanggal : 5 Oktober 2021
Topik Praktikum: ADT Queue
Deskripsi: File ini berisi ADT queu yang memiliki header "queue.h" (Pra Praktikum 7)
*/

// /* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

// /* ********* Prototype ********* */
boolean isEmptyQ(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFullQ(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (IDX_HEAD(q) == 0) && (IDX_TAIL(q) == QUEUECAPACITY - 1);
}
int lengthQ(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    // KAMUS LOKAL
    int lengthQ;
    // ALGORITMA
    if (isEmptyQ(q)) {
        lengthQ = 0;
    } else {
        lengthQ = IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    return lengthQ;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Barang val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    // KAMUS LOKAL
    int i;
    // ALGORITMA
    if (isEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        if (IDX_TAIL(*q) == (QUEUECAPACITY - 1)) {
            for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, Barang *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    *val = HEAD(*q);
    if (lengthQ(*q) == 1) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    if (isEmpty(q)) {
        printf("[]");
    } else { // q tidak kosong
        printf("[");
        for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            if (i == IDX_TAIL(q)) { // Untuk elemen terakhir, tidak perlu menuliskan koma setelahnya
                printf("%d", (q).buffer[i]);
            } else {
                printf("%d,", (q).buffer[i]);
            }
        }
        printf("]");
    }
}

// /* *** Display Queue *** */
// void displayQueue(Queue q)
// /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
//    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
//    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
// /* I.S. q boleh kosong */
// /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika Queue kosong : menulis [] */
// {
//     // KAMUS LOKAL
//     int i;
//     // ALGORITMA
//     printf("[");
//     if (!isEmptyQ(q)) {
//         for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
//             printf("%d", q.buffer[i]);
//             if (i != IDX_TAIL(q)) {
//                 printf(",");
//             }
//         }
//     }
//     printf("]");
// }