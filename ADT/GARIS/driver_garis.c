/* File: driver_garis.c */
/* *** Driver ABSTRACT DATA TYPE GARIS *** */

#include <stdio.h>
#include "garis.h"
#include "point.h"

int main() {
    /* KAMUS */
    GARIS L, L2;
    float deltaX, deltaY;

    /* ALGORITMA */
    /* Test Baca/Tulis */
    printf("Test Baca/Tulis\n");
    BacaGARIS(&L);
    TulisGARIS(L);
    printf("\n");

    /* Test operasi garis */
    printf("Panjang garis: %f\n", PanjangGARIS(L));
    printf("Gradien garis: %f\n", Gradien(L));
    printf("Masukkan deltaX dan deltaY: ");
    scanf("%f %f", &deltaX, &deltaY);
    GeserGARIS(&L, deltaX, deltaY);
    TulisGARIS(L);

    /* Test Predikat */
    BacaGARIS(&L2);
    TulisGARIS(L2);
    printf("Gradien garis: %f\n", Gradien(L2));
    printf("\n");
    if (IsTegakLurus(L, L2)) {
        printf("L1 dan L2 tegak lurus");
    }
    if (IsSejajar(L, L2)) {
        printf("L1 dan L2 sejajar");
    }

    return 0;
}