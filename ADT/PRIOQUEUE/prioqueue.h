/* File : prioqueue.h */
/* Representasi priority queue dengan array eksplisit dan alokasi stastik */
/* Queue terurut mengecil berdasarkan elemen score (nilai Daspro) */
/* Jika score sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */
#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "boolean.h"
#include "barang.h"

/* Konstanta */
#define IDX_UNDEF -1
#define PRIOQUEUECAPACITY 30

/* Deklarasi ElType */
// typedef struct {
// 	int id;         /* id mahasiswa */
// 	int tArrival;   /* waktu kedatangan */
// 	int score;      /* skor Daspro */
// 	int dService;   /* durasi/lama persiapan makanan untuk mahasiswa */
// } ElType;

/* Definisi PrioQueue */
typedef struct {
	Barang buffer[PRIOQUEUECAPACITY];
	int idxHead;
	int idxTail;
} PrioQueue;

/* ********* AKSES (Selektor) ********* */
/* Jika pq adalah PrioQueue, maka akses elemen : */
#define IDX_HEADPRIO(pq) (pq).idxHead
#define IDX_TAILPRIO(pq) (pq).idxTail
#define     HEADPRIO(pq) (pq).buffer[(pq).idxHead]
#define     TAILPRIO(pq) (pq).buffer[(pq).idxTail]

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

boolean isEmptyPrio(PrioQueue pq);
/* Mengirim true jika pq kosong: lihat definisi di atas */

boolean isFullPrio(PrioQueue pq);
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */

int lengthPrio(PrioQueue pq);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika pq kosong. */

/*** Primitif Add/Delete ***/
void enqueuePrio(PrioQueue *pq, Barang val);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen pq
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeuePrio(PrioQueue * pq, Barang *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd
I.S., HEAD dan IDX_HEAD "mundur"; 
        pq mungkin kosong */

#endif
