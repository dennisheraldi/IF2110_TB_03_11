#include "list.h"
/*
Nama    : David Karel Halomoan
NIM     : 16520354
*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateList(List *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLS(List l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
    return NEFF(l);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLS(List l, int i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return i >= 0 && i < LISTCAPACITY;
}
boolean isIdxEffLS(List l, int i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return i >= 0 && i < NEFF(l);
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
    CreateList(l);
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
    for (i = 0; i < lengthLS(l); i++) {
        printf("%d", ELMTLS(l, i));
        if (i < lengthLS(l) - 1) {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
List plusMinusTab(List l1, List l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
    int i = 0;
    List l;
    CreateList(&l);
    if (plus) {
        while (isIdxEffLS(l1, i)){
            ELMTLS(l, i) = ELMTLS(l1, i) + ELMTLS(l2, i);
            i++;
        }
    } else {// !plus
        while (isIdxEffLS(l1, i)){
            ELMTLS(l, i) = ELMTLS(l1, i) - ELMTLS(l2, i);
            i++;
        }
    }
    NEFF(l) = NEFF(l1);
    return l;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqualLS(List l1, List l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
    boolean equal;
    equal = NEFF(l1) == NEFF(l2);
    int i = 0;
    while (isIdxEffLS(l1, i) && equal) {
        if (ELMTLS(l1, i) != ELMTLS(l2, i)) {
            equal = false;
        }
        i++;
    }
    return equal;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfLS(List l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMTLS(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    int idx, i;
    boolean found;
    i = 0;
    found = false;
    while (isIdxEffLS(l, i) && !found) {
        if (ELMTLS(l, i) == val) {
            idx = i;
            found = true;
        }
        i++;
    }
    return found ? idx : IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremesLS(List l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
    int i = 0;
    *max = *min = ELMTLS(l, 0);
    while (isIdxEffLS(l, i)) {
        if (ELMTLS(l, i) > *max) {
            *max = ELMTLS(l, i);
        }
        if (ELMTLS(l, i) < *min) {
            *min = ELMTLS(l, i);
        }
        i++;
    }
}

/* ********** OPERASI LAIN ********** */
boolean isAllEvenLS(List l)
/* Menghailkan true jika semua elemen l genap */
{
    boolean even;
    int i = 0;
    even = !(isEmptyLS(l));
    while (isIdxEffLS(l, i) && even) {
        if (ELMTLS(l, i) % 2 != 0) {
            even = false;
        }
        i++;
    }
    return even;
}

/* ********** SORTING ********** */
void sortLS(List *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    if (!isEmptyLS(*l) && lengthLS(*l) != 1) {
        int Pass, i;
        // Insertion sort
        if (asc) {
            for (Pass = 1; Pass < lengthLS(*l); Pass++) {
                i = Pass;
                while (ELMTLS(*l, i) < ELMTLS(*l, i - 1) && i > 0) {
                    int key = ELMTLS(*l, i);
                    ELMTLS(*l, i) = ELMTLS(*l, i - 1);
                    ELMTLS(*l, i - 1) = key;
                    i--;
                }
            }
        }
        else {// !asc
            for (Pass = 1; Pass < lengthLS(*l); Pass++) {
                i = Pass;
                while (ELMTLS(*l, i) > ELMTLS(*l, i - 1) && i > 0) {
                    int key = ELMTLS(*l, i);
                    ELMTLS(*l, i) = ELMTLS(*l, i - 1);
                    ELMTLS(*l, i - 1) = key;
                    i--;
                }
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLS(List *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
    int i = 0;
    while (isIdxEffLS(*l, i)) {
        i++;
    }
    ELMTLS(*l, i) = val;
    NEFF(*l)++;
}
void deleteLastLS(List *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    int i = 0;
    while (isIdxEffLS(*l, i)) {
        i++;
    }
    *val = ELMTLS(*l, i - 1);
    ELMTLS(*l, i - 1) = VAL_UNDEF;
    NEFF(*l)--;
}