// NAMA: MUHAMMAD GERALD AKBAR GIFFERA
// NIM: 13520143
// KELAS: K03
/* File : list_linked.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* ElType adalah integer*/

#include "list_linked.h"
#include <stdio.h>

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinked(ListLinked *l)
{
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(ListLinked l)
{
    return (l == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Barang getElmt(ListLinked l, int idx)
{
    Address p;
    p = l;
    int ctr = 0;
    while (ctr != idx)
    {
        ctr++;
        p = NEXT(p);
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(ListLinked *l, int idx, Barang val)
{
    Address p = *l;
    int ctr = 0;
    while (ctr < idx)
    {
        p = NEXT(p);
        ctr++;
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

/*int indexOf(ListLinked l, Barang val)
{
    boolean found = false;
    int idx = 0;
    Address p = l;
    while (p != NULL && !found)
    {
        if (INFO(p) == val)
        {
            found = true;
        }
        else
        {
            idx++;
            p = NEXT(p);
        }
        
    }
    if (found)
    {
        return idx;
    }
    else
    {
        return IDX_UNDEF;
    }
}*/
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

int length(ListLinked l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    Address p = l;
    int ctr = 0;
    while (p != NULL)
    {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
    
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(ListLinked *l, Barang val)
{
    Address p;
    p = newNode(val);
    if (p != NULL)
    {
        NEXT(p) = *l;
        *l = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(ListLinked *l, Barang val)
{
    Address p,last;
    if (isEmpty(*l))
    {
        insertFirst(l,val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            last = *l;
            while (NEXT(last) != NULL)
            {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(ListLinked *l, Barang val, int idx)
{
    int ctr = 0;
    Address p,loc;
    if (idx == 0)
    {
        insertFirst(l,val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            loc = *l;
            while (ctr != idx-1)
            {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(ListLinked *l, Barang *val)
{
    Address p;
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(ListLinked *l, Barang *val)
{
    Address p = *l;
    Address loc = NULL;
    while (NEXT(p) != NULL)
    {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL)
    {
        *l = NULL;
    }
    else
    {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(ListLinked *l, int idx, Barang *val)
{
    int ctr;
    Address p,loc;
    if (idx == 0)
    {
        deleteFirst(l,val);
    }
    else if (idx == (length(*l)-1))
    {
        deleteLast(l,val);
    }
    else
    {
        ctr = 0;
        loc = *l;
        while (ctr != idx-1)
        {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
/* void displayList(List l)
{
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        Address p = l;
        while (p != NULL)
        {
            if (NEXT(p) == NULL)
            {
                printf("%d",INFO(p));
            }
            else
            {
                printf("%d,",INFO(p));
            }
            p = NEXT(p);
        }
        printf("]");
    }
} */
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */





/****************** PROSES TERHADAP LIST ******************/
/*ListLinked concat(ListLinked l1, ListLinked l2)
{
    Address p;
    ListLinked l3;
    CreateList(&l3);
    p = l1;
    while (p != NULL)
    {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL)
    {
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    return l3;
}*/
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */