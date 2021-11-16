/* File: driver_time.c */
/* Driver ADT TIME */

#include <stdio.h>
#include "time.h"

int main () {
    /* KAMUS */
    TIME T1, T2;
    long detik;
    int N;

    /* ALGORITMA */
    /* Bagian Manual penggunaan Konstruktor */
    printf("\n\n----Pembuatan TIME 1 Secara Manual----");
    T1 = MakeTIME(10, 20, 30);
    printf("Pembuatan manual TIME 1: ");
    TulisTIME(T1);

    /* Pembuatan dengan BacaTIME */
    printf("\n\n----Pembuatan TIME 1 dengan Fungsi BacaTIME----");
    printf("\nMasukkan TIME 1 dengan format jam menit detik: ");
    BacaTIME(&T1);
    printf("TIME 1 yang dibaca adalah: ");
    TulisTIME(T1);

    printf("\n\n----Pembuatan TIME 2 dengan Fungsi BacaTIME----");
    printf("\nMasukkan TIME 2 dengan format jam menit detik: ");
    BacaTIME(&T2);
    printf("TIME 2 yang dibaca adalah: ");
    TulisTIME(T2);

    /* Konversi Tipe */
    printf("\n\n----Konversi TIME ke dalam Detik----\n");
    TulisTIME(T1);
    printf("\nTIME 1 dalam detik: ");
    printf("%ld", TIMEToDetik(T1));

    printf("\n\n----Konversi Detik ke Bentuk TIME----");
    printf("\nMasukkan detik (prekondisi >= 0): ");
    scanf("%ld", &detik);
    printf("Representasi detik dalam TIME: ");
    TulisTIME(DetikToTIME(detik));

    /* Operator Relasional */
    printf("\n\n----Operasi Relasional----");
    printf("\nTIME 1: ");
    TulisTIME(T1);
    printf("\nTIME 2: ");
    TulisTIME(T2);
    if (TEQ(T1, T2)) {
        printf("\nTIME 1 sama dengan TIME 2");
    } 
    if (TNEQ(T1, T2)) {
        printf("\nTIME 1 tidak sama dengan TIME 2");
    }
    if (TLT(T1, T2)) {
        printf("\nTIME 1 lebih kecil dari TIME 2");
    }
    if (TGT(T1, T2)) {
        printf("\nTIME 1 lebih besar dari TIME 2");
    }

    /* Operator Aritmatika */
    printf("\n\n----Operasi Aritmatika----");
    printf("\nTIME 1: ");
    TulisTIME(T1);
    printf("\nSatu detik setelah TIME 1: ");
    TulisTIME(NextDetik(T1));
    printf("\nMasukkan N: ");
    scanf("%d", &N);
    printf("N detik setelah TIME 1: ");
    TulisTIME(NextNDetik(T1, N));
    
    printf("\nTIME 1: ");
    TulisTIME(T1);
    printf("\nSatu detik sebelum TIME 1: ");
    TulisTIME(PrevDetik(T1));
    printf("\nMasukkan N: ");
    scanf("%d", &N);
    printf("N detik sebelum TIME 1: ");
    TulisTIME(PrevNDetik(T1, N));

    /* Penghitungan Durasi */
    printf("\n\n----Durasi antara Dua Waktu----");
    printf("\nTIME 1: ");
    TulisTIME(T1);
    printf("\nTIME 2: ");
    TulisTIME(T2);
    printf("\nDurasi antara TIME 1 dengan TIME 2: %ld detik", Durasi(T1, T2));

    float exeKiller;
    printf("\n\n(End of Program - Enter non-whitespace character to exit)");
    scanf("%f", &exeKiller); 
    /* for executable file */
    
    return 0;
}