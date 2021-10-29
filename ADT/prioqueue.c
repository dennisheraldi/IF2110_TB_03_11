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
    IDX_HEADPRIO(*pq) = IDX_UNDEF;
    IDX_TAILPRIO(*pq) = IDX_UNDEF;
}

boolean isEmptyPrio(PrioQueue pq)
/* Mengirim true jika pq kosong: lihat definisi di atas */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (IDX_HEADPRIO(pq) == IDX_UNDEF) && (IDX_TAILPRIO(pq) == IDX_UNDEF);
}

boolean isFullPrio(PrioQueue pq)
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
{
    // KAMUS LOKAL
    // ALGORITMA
    return (IDX_HEADPRIO(pq) == 0) && (IDX_TAILPRIO(pq) == PRIOQUEUECAPACITY - 1);
}

int lengthPrio(PrioQueue pq)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */
{
    // KAMUS LOKAL
    int length;
    // ALGORITMA
    if (isEmptyPrio(pq)) {
        length = 0;
    } else {
        length = IDX_TAILPRIO(pq) - IDX_HEADPRIO(pq) + 1;
    }
    return length;
}

/*** Primitif Add/Delete ***/
void enqueuePrio(PrioQueue *pq, Barang val)
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAILPRIO "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    // KAMUS LOKAL
    int i, iterasi;
    // ALGORITMA
    if (isEmptyPrio(*pq)) {
        IDX_HEADPRIO(*pq) = 0;
        IDX_TAILPRIO(*pq) = 0;
        TAILPRIO(*pq) = val;
    } else {
        if (IDX_TAILPRIO(*pq) == (PRIOQUEUECAPACITY - 1)) {
            for (i = IDX_HEADPRIO(*pq); i <= IDX_TAILPRIO(*pq); i++) {
                (*pq).buffer[i - IDX_HEADPRIO(*pq)] = (*pq).buffer[i];
            }
            IDX_TAILPRIO(*pq) -= IDX_HEADPRIO(*pq);
            IDX_HEADPRIO(*pq) = 0;
        }
        i = lengthPrio(*pq) - 1;
        while (ORDER_TIME((*pq).buffer[i]) > ORDER_TIME(val) && i >= IDX_HEADPRIO(*pq)) {
            (*pq).buffer[i + 1] = (*pq).buffer[i];
            i--;
        }
        (*pq).buffer[i + 1] = val;
        IDX_TAILPRIO(*pq)++;
    }
}

void dequeuePrio(PrioQueue * pq, Barang *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEADPRIO "mundur"; 
        pq mungkin kosong */
{
    // KAMUS LOKAL
    // ALGORITMA
    *val = HEADPRIO(*pq);
    if (lengthPrio(*pq) == 1) {
        IDX_HEADPRIO(*pq) = IDX_UNDEF;
        IDX_TAILPRIO(*pq) = IDX_UNDEF;
    } else {
        IDX_HEADPRIO(*pq)++;
    }
}