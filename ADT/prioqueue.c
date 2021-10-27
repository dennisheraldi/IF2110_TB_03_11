#include <stdio.h>
#include "prioqueue.h"

/*
Nama: David Karel Halomoan
NIM: 13520154
Tanggal : 7 Oktober 2021
Topik Praktikum: ADT Queue
Deskripsi: File ini berisi file c dari header "prioqueue.h" (Praktikum 7 Soal 2)
*/

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq)
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmpty(PrioQueue pq)
/* Mengirim true jika pq kosong: lihat definisi di atas */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq)
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (IDX_HEAD(pq) == 0) && (IDX_TAIL(pq) == PRIOQUEUECAPACITY - 1);
}

int length(PrioQueue pq)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */
{
    // KAMUS LOKAL
    int length;
    // ALGORITMA
    if (isEmpty(pq)) {
        length = 0;
    } else {
        length = IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    }
    return length;
}

/*** Primitif Add/Delete ***/
void enqueue(PrioQueue *pq, ElType val)
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    // KAMUS LOKAL
    int i, iterasi;
    // ALGORITMA
    if (isEmpty(*pq)) {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    } else {
        if (IDX_TAIL(*pq) == (PRIOQUEUECAPACITY - 1)) {
            for (i = IDX_HEAD(*pq); i <= IDX_TAIL(*pq); i++) {
                (*pq).buffer[i - IDX_HEAD(*pq)] = (*pq).buffer[i];
            }
            IDX_TAIL(*pq) -= IDX_HEAD(*pq);
            IDX_HEAD(*pq) = 0;
        }
        iterasi = length(*pq) - 1;
        while ((val.score > (*pq).buffer[iterasi].score) && (iterasi >= IDX_HEAD(*pq))) {
            (*pq).buffer[iterasi + 1] = (*pq).buffer[iterasi];
            iterasi--;
        }
        while ((val.tArrival < (*pq).buffer[iterasi].tArrival) 
                && 
                (iterasi >= IDX_HEAD(*pq)) 
                && 
                (val.score == (*pq).buffer[iterasi].score)) {

            (*pq).buffer[iterasi + 1] = (*pq).buffer[iterasi];
            iterasi--;
        }
        (*pq).buffer[iterasi + 1] = val;
        IDX_TAIL(*pq)++;
    }
}

void dequeue(PrioQueue * pq, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    *val = HEAD(*pq);
    if (length(*pq) == 1) {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    } else {
        IDX_HEAD(*pq)++;
    }
}