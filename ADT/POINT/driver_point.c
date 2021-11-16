/* File: driver_point.c */
/* *** Driver ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include "point.h"

int main () {
    /* KAMUS */
    POINT P1, P2;
    float deltaX, deltaY, Sudut;

    /* ALGORITMA */
    /* Membentuk POINT 1 */
    printf("----Insert POINT 1----");
    printf("\nMasukkan nilai absis dan ordinat untuk POINT 1: ");
    BacaPOINT(&P1);
    printf("Titik POINT 1 yang dibaca adalah: ");
    TulisPOINT(P1);

    /* Update nilai POINT */
    printf("\n\n----Update POINT 1----");
    printf("\nMasukkan nilai absis dan ordinat yang baru untuk POINT 1: ");
    BacaPOINT(&P1);
    printf("Titik POINT 1 yang baru adalah: ");
    TulisPOINT(P1);

    /* Membentuk POINT 2 */
    printf("\n\n----Insert POINT 2----\n");
    printf("Masukkan nilai absis dan ordinat untuk POINT 2: ");
    BacaPOINT(&P2);
    printf("Titik POINT 2 yang dibaca adalah: ");
    TulisPOINT(P2);

    /* Operasi Relasional */
    printf("\n\n----Operasi Relasional----\n");
    if (EQ(P1, P2)) {
        printf("POINT 1 sama dengan POINT 2");
    } else if (NEQ(P1, P2)) {
        printf("POINT 1 tidak sama dengan POINT 2");
    }

    /* Menentukan Posisi Titik */
    printf("\n\n----Posisi Titik terhadap Sumbu Kartesius----\n");
    if (IsOrigin(P1)) {
        TulisPOINT(P1);
        printf(" merupakan titik origin\n");
    } else {
        TulisPOINT(P1);
        printf(" bukan merupakan titik origin\n");
    }

    if (IsOnSbX(P1)) {
        TulisPOINT(P1);
        printf(" merupakan titik yang berada pada sumbu x\n");
    } else {
        TulisPOINT(P1);
        printf(" bukan merupakan titik yang berada pada sumbu x\n");      
    }

    if (IsOnSbY(P1)) {
        TulisPOINT(P1);
        printf(" merupakan titik yang berada pada sumbu y\n");
    } else {
        TulisPOINT(P1);
        printf(" bukan merupakan titik yang berada pada sumbu y\n");  
    }

    TulisPOINT(P1);
    printf(" terletak pada kuadran %d", Kuadran(P1));

    /* Operasi Lain */
    printf("\n\n----Operasi-Operasi Lain pada POINT 1----\n");
    printf("POINT 1: ");
    TulisPOINT(P1);
    /* penambahan 1 pada absis atau ordinat */
    printf("\nPOINT 1 apabila absis ditambah 1: ");
    TulisPOINT(NextX(P1));
    printf("\nPOINT 1 apabila ordinat ditambah 1: ");
    TulisPOINT(NextY(P1));
    /* pergeseran titik sejauh deltaX dan deltaY */
    printf("\nMasukkan besar pergeseran absis dan ordinat dalam format (deltaX deltaY): ");
    scanf("%f %f", &deltaX, &deltaY);
    printf("POINT 1 setelah mengalami pergeseran: ");
    TulisPOINT(PlusDelta(P1, deltaX, deltaY));
    /* mirror titik terhadap sumbu x atau y */
    printf("\nPOINT 1 setelah dicerminkan terhadap sumbu x: ");
    TulisPOINT(MirrorOf(P1, true));
    printf("\nPOINT 1 setelah dicerminkan terhadap sumbu y: ");
    TulisPOINT(MirrorOf(P1, false));
    /* menghitung jarak titik terhadap origin */
    printf("\nJarak antara POINT dengan titik (0,0) adalah %f", Jarak0(P1));
    /* menghitung jarak dua titik atau panjang garis yang dibentuk oleh dua titik */
    printf("\nPanjang garis yang dibentuk oleh POINT 1 dan POINT 2 adalah %f", Panjang(P1, P2));
    
    /* Operasi yang Mengubah/Meng-update nilai POINT */
    printf("\n\n----Operasi-Operasi yang Meng-update nilai POINT----\n");
    printf("POINT 1: ");
    TulisPOINT(P1);
    /* pergeseran titik sejauh deltaX dan deltaY */
    printf("\nMasukkan besar pergeseran absis dan ordinat dalam format (deltaX deltaY): ");
    scanf("%f %f", &deltaX, &deltaY);
    Geser(&P1, deltaX, deltaY);
    printf("POINT 1 setelah mengalami pergeseran: ");
    TulisPOINT(P1);
    /* 
    Di sini POINT 1 telah berubah nilainya dan akan di-update terus untuk 
    setiap operasi yang ada. Oleh karena itu, untuk operasi-operasi berikutnya, 
    akan ditampilkan terlebih dahulu nilai POINT 1 yang terbaru.
    */
    /* menggeser titik ke sumbu x */
    printf("\nPOINT 1: ");
    TulisPOINT(P1);
    GeserKeSbX(&P1);
    printf("\nPOINT 1 setelah digeser ke sumbu x: ");
    TulisPOINT(P1);
    /* menggeser titik ke sumbu y */
    printf("POINT 1: ");
    TulisPOINT(P1);
    GeserKeSbY(&P1);
    printf("\nPOINT 1 setelah digeser ke sumbu y: ");
    TulisPOINT(P1);
    /* 
    Pada tahap ini, POINT 1 pasti bernilai (0,0) akibat telah digeser ke
    sumbu x dan sumbu y. Oleh karena itu, implementasi untuk fungsi/prosedur 
    selanjutnya akan dilakukan juga pada POINT 2 untuk mendapatkan pengecekan
    yang lebih akurat.
    */
    /* mirror titik terhadap sumbu x atau y */
    printf("\nPOINT 1: ");
    TulisPOINT(P1);
    printf("\nPOINT 2: ");
    TulisPOINT(P2);
    Mirror(&P1, true);
    printf("\nPOINT 1 setelah dicerminkan terhadap sumbu x: ");
    TulisPOINT(P1);
    Mirror(&P1, false);
    printf("\nPOINT 1 setelah dicerminkan terhadap sumbu y: ");
    TulisPOINT(P1);
    Mirror(&P2, true);
    printf("\nPOINT 2 setelah dicerminkan terhadap sumbu x: ");
    TulisPOINT(P2);
    Mirror(&P2, false);
    printf("\nPOINT 2 setelah dicerminkan terhadap sumbu y: ");
    TulisPOINT(P2);
    /* menggeser titik sebesar Sudut derajat dengan sumbu titik (0,0) */
    printf("\nPOINT 1: ");
    TulisPOINT(P1);
    printf("\nPOINT 2: ");
    TulisPOINT(P2);
    printf("\nMasukkan besar sudut perputaran (searah jarum jam): ");
    scanf("%f", &Sudut);
    Putar(&P1, Sudut);
    printf("POINT 1 setelah diputar sejauh %.2f derajat: ", Sudut);
    TulisPOINT(P1);
    Putar(&P2, Sudut);
    printf("\nPOINT 2 setelah diputar sejauh %.2f derajat: ", Sudut);
    TulisPOINT(P2);

    float exeKiller;
    printf("\n\n(End of Program - Enter non-whitespace character to exit)");
    scanf("%f", &exeKiller); 
    /* for executable file */
    
    return 0;
}