#include "list.h"
#include <stdio.h>

/* DEFINISI LIST STATIS DENGAN REPRESENTASI FISIK EKSPLISIT ACAK */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListLS(List *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
    // Kamus
    int i;

    // Algoritma
    for(i=0; i<LISTCAPACITY; i++) {
        ELMTLS(*l,i) = VAL_UNDEF;
        NEFF(*l) = 0;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int nbELMTLS(List l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
    return NEFF(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLS(List l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
    return NEFF(l) == 0;
}
/* *** Test List penuh *** */
boolean isFullLS(List l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return NEFF(l) == LISTCAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListLS(List *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    int n, i;
    scanf("%d", &n);
    while (!(n >= 0 && n <= LISTCAPACITY)) {
        scanf("%d", &n);
    }
    CreateListLS(l);
    for (i = 0; i < n; i++) {
        scanf("%d", &ELMTLS(*l, i));
    }
    NEFF(*l) = n;
}
void displayListLS(List l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    int i;
    printf("[");
    for (i = 0; i < LISTCAPACITY; i++) {
        printf("%d", ELMTLS(l, i));
        if (i < LISTCAPACITY - 1) {
            printf(",");
        }
    }
    printf("]");
}

void insertElmt(List *l, ElType val){
    int i = 0;
    boolean found = false;
    while (i<LISTCAPACITY && !found) {
        if (ELMTLS(*l,i) == VAL_UNDEF){
            ELMTLS(*l,i) = val;
            found = true;
            NEFF(*l)++;
            
        }
        i++;
    }
}

void deleteElmt(List *l, ElType idx){
    ELMTLS(*l,idx) = VAL_UNDEF;
    NEFF(*l)--;
}