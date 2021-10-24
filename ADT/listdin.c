#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

/*
Nama  : David Karel
NIM   : 13520154
*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
    /*KAMUS*/
    /*ALGORITMA*/
    BUFFER(*l) = (int *)malloc(sizeof(int) * capacity);
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocate(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    /*KAMUS*/
    /*ALGORITMA*/
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLD(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    /*KAMUS*/
    int length;
    /*ALGORITMA*/
    return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getLastIdxLD(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLD(ListDin l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    /*KAMUS*/
    /*ALGORITMA*/
    return i >= 0 && i < CAPACITY(l);
}
boolean isIdxEffLD(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return i >= 0 && i < NEFF(l);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyLD(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return NEFF(l) == 0;
}
boolean isFullLD(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
    /*KAMUS*/
    /*ALGORITMA*/
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListLD(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
    /*KAMUS*/
    int N, i;
    /*ALGORITMA*/
    scanf("%d", &N);
    while (!(N >= 0 && N <= CAPACITY(*l))) {
        scanf("%d", &N);
    }
    for (i = 0; i < N; i++) {
        scanf("%d", &ELMTLD(*l, i));
    }
    NEFF(*l) = N;
}
void displayListLD(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
    /*KAMUS*/   
    int i;
    /*ALGORITMA*/
    printf("[");
    for (i = 0; i < NEFF(l); i++) {
        printf("%d", ELMTLD(l, i));
        if (i < lengthLD(l) - 1) {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
    /*KAMUS*/
    ListDin l;
    int i;
    /*ALGORITMA*/
    CreateListDin(&l, NEFF(l1));
    NEFF(l) = NEFF(l1);
    if (plus) {
        for (i = 0; i < lengthLD(l); i++) {
            ELMTLD(l, i) = ELMTLD(l1, i) + ELMTLD(l2, i);
        }
    } else {// !plus
        for (i = 0; i < lengthLD(l); i++) {
            ELMTLD(l, i) = ELMTLD(l1, i) - ELMTLD(l2, i);
        }
    }
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualLD(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    /*KAMUS*/ 
    int i;
    boolean sama;
    /*ALGORITMA*/
    sama = true;
    if (lengthLD(l1) != lengthLD(l2)) {
        sama = false;
    }

    i = 0;
    while (isIdxEffLD(l1, i) && sama) {
        if (ELMTLD(l1, i) != ELMTLD(l2, i)) {
            sama = false;
        }
        i++;
    }
    return sama;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfLD(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
    /*KAMUS*/ 
    IdxType i;
    /*ALGORITMA*/
    if (isEmptyLD(l)) {
        i = IDX_UNDEF;
    } else {// !isEmpty(l)
        i = 0;
        while (isIdxEffLD(l, i) && ELMTLD(l, i) != val) {
            i++;
        }
        if (!isIdxEffLD(l, i)) {
            i = IDX_UNDEF;
        }
    }
    return i;
}

/* ********** NILAI EKSTREM ********** */
void extremesLD(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    /*KAMUS*/ 
    int i;
    /*ALGORITMA*/
    *max = *min = ELMTLD(l, 0);
    for (i = 1; i < lengthLD(l); i++) {
        if (ELMTLD(l, i) > *max) {
            *max = ELMTLD(l, i);
        }
        if (ELMTLD(l, i) < *min) {
            *min = ELMTLD(l, i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyListLD(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    /*KAMUS*/
    int i;
    /*ALGORITMA*/
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < lengthLD(lIn); i++) {
        ELMTLD(*lOut, i) = ELMTLD(lIn, i);
    }
}
ElType sumListLD(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
    /*KAMUS*/
    int i;
    ElType sum;
    /*ALGORITMA*/
    if (isEmptyLD(l)) {
        sum = 0;
    } else {
        sum = 0;
        for (i = 0; i < lengthLD(l); i++) {
            sum += ELMTLD(l, i);
        }
    }
    return sum;
}
int countValLD(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
    /*KAMUS*/
    int i;
    int count;
    /*ALGORITMA*/
    count = 0;
    for (i = 0; i < lengthLD(l); i++) {
        if (ELMTLD(l, i) == val) {
            count++;
        }
    }
    return count;
}
boolean isAllEvenLD(ListDin l)
/* Menghailkan true jika semua elemen l genap. l boleh kosong */
{
    /*KAMUS*/
    boolean even;
    int i;
    /*ALGORITMA*/
    if (isEmptyLD(l)) {
        even = true;
    } else {
        even = true;
        i = 0;
        while (isIdxEffLD(l, i) && even) {
            if (ELMTLD(l, i) % 2 != 0) {
                even = false;
            }
            i++;
        }
    }
    return even;
}

/* ********** SORTING ********** */
void sortLD(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    /*KAMUS*/
    int Pass, i;
    /*ALGORITMA*/
    if (!isEmptyLD(*l) && lengthLD(*l) != 1) {
        // Insertion sort
        if (asc) {
            for (Pass = 1; Pass < lengthLD(*l); Pass++) {
                i = Pass;
                while (ELMTLD(*l, i) < ELMTLD(*l, i - 1) && i > 0) {
                    int key = ELMTLD(*l, i);
                    ELMTLD(*l, i) = ELMTLD(*l, i - 1);
                    ELMTLD(*l, i - 1) = key;
                    i--;
                }
            }
        }
        else {// !asc
            for (Pass = 1; Pass < lengthLD(*l); Pass++) {
                i = Pass;
                while (ELMTLD(*l, i) > ELMTLD(*l, i - 1) && i > 0) {
                    int key = ELMTLD(*l, i);
                    ELMTLD(*l, i) = ELMTLD(*l, i - 1);
                    ELMTLD(*l, i - 1) = key;
                    i--;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLD(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMTLD(*l, lengthLD(*l)) = val;
    NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastLD(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    /*KAMUS*/
    /*ALGORITMA*/
    *val = ELMTLD(*l, getLastIdxLD(*l));
    NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    /*KAMUS*/
    ListDin temp;
    int i;
    /*ALGORITMA*/
    CreateListDin(&temp, CAPACITY(*l) + num);
    for (i = 0; i < length(*l); i++) {
        ELMTLD(temp, i) = ELMTLD(*l, i);
    }
    NEFF(temp) = NEFF(*l);
    dealocate(l);
    copyList(temp, l);
    dealocate(&temp);
}

void shrinkList(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
    /*KAMUS*/
    ListDin temp;
    int i;
    /*ALGORITMA*/
    CreateListDin(&temp, CAPACITY(*l) - num);
    for (i = 0; i < length(*l); i++) {
        ELMTLD(temp, i) = ELMTLD(*l, i);
    }
    NEFF(temp) = NEFF(*l);
    dealocate(l);
    copyList(temp, l);
    dealocate(&temp);
}

void compactList(ListDin *l)
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */
{
    /*KAMUS*/
    ListDin temp;
    int i;
    /*ALGORITMA*/
    CreateListDin(&temp, NEFF(*l));
    for (i = 0; i < length(*l); i++) {
        ELMTLD(temp, i) = ELMTLD(*l, i);
    }
    NEFF(temp) = NEFF(*l);
    dealocate(l);
    copyList(temp, l);
    dealocate(&temp);
}