/* MODUL LIST INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer dengan elemen 
   positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LIST_H
#define LIST_H

#include "../boolean.h"

/*  Kamus Umum */
#define LISTCAPACITY 5 //kapasitas untuk inventory pembelian gadget
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType;  /* type elemen List */
typedef struct {
   ElType contents[LISTCAPACITY]; /* memori tempat penyimpan elemen (container) */
   int nEff;
} List;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListPos, cara deklarasi dan akses: */
/* Deklarasi : l : ListPos */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMTLS(l, i) (l).contents[(i)]
#define NEFF(l) (l).nEff

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListLS(List *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int nbELMTLS(List l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

// /* ********** Test Indeks yang valid ********** */
// boolean isIdxValidLS(List l, int i);
// /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
// /* yaitu antara indeks yang terdefinisi utk container*/
// boolean isIdxEffLS(List l, int i);
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
// /* yaitu antara 0..length(l)-1 */

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test List kosong *** */
boolean isEmptyLS(List l);
// /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
// /* *** Test List penuh *** */
boolean isFullLS(List l);
// /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListLS(List *l);
// /* I.S. l sembarang */
// /* F.S. List l terdefinisi */
// /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
// /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
// /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
// /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
// /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
//           Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
// /*    Jika n = 0; hanya terbentuk List kosong */
void displayListLS(List l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

void insertElmt(List *l, ElType val);

void deleteElmt(List *l, ElType idx);



#endif