/* File: driver_matrix.c */
/* *** Driver ABSTRACT DATA TYPE MATRIX *** */

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "boolean.h"

#define nl printf("\n")

int main() {
    // Kamus
    Matrix M1;
    Matrix M2;
    Matrix M3;
    int nb;
    int nk;
    int i;
    int j;
    char ctemp;

    // Algoritma
    printf("BACA MATRIKS"); nl;
    printf("Masukkan jumlah baris: "); scanf("%d", &nb);
    printf("Masukkan jumlah kolom: "); scanf("%d", &nk);
    printf("press enter...");
    scanf("%c", &ctemp);
    printf("pressed...");
    printf("M1");
    readMatrix(&M1, nb, nk);
    printf("press enter...");
    scanf("%c", &ctemp);
    printf("pressed...");
    printf("M2");
    readMatrix(&M2, nb, nk);

    nl; printf("PERINDEKSAN MATRIKS"); nl;
    printf("First Index Baris : 0"); nl;
    printf("First Index Kolom : 0"); nl;
    printf("Last Index Baris : %d", getLastIdxRow(M1)); nl;
    printf("Last Index Kolom : %d\n", getLastIdxCol(M1));
    printf("Masukkan i: "); scanf("%d", &i);
    printf("Masukkan j: "); scanf("%d", &j);
    if (isIdxEffM(M1, i, j)) {
        printf("Indeks efektif\n");
    } else {
        printf("Indeks tidak efektif\n");
    }

    nl; printf("EQUIVALENCE"); nl;
    if (isEqual(M1, M2)) {
        printf("Matriks M1 dan M2 sama\n");
    } else {
        printf("Matriks M1 dan M2 tidak sama\n");
    }
    if (isSizeEqual(M1, M2)) {
        printf("Matriks M1 dan M2 sama ukuran efektifnya\n");
    } else {
        printf("Matriks M1 dan M2 tidak sama ukuran efektifnya\n");
    }
    
    nl; printf("JENIS MATRIKS"); nl;
    if (isSquare(M1)) {
        printf("Matriks M1 adalah matriks bujur sangkar\n");
    } else {
        printf("Matriks M1 bukan matriks bujur sangkar\n");
    }
    if (isSymmetric(M1)) {
        printf("Matriks M1 simetris\n");
    } else {
        printf("Matriks M1 tidak simetris\n");
    } 
    if (isIdentity(M1)) {
        printf("Matriks M1 adalah matriks identitas\n");
    } else {
        printf("Matriks M1 bukan matriks identitas\n");
    }
    if (isSparse(M1)) {
        printf("Matriks M1 adalah matriks jarang\n");
    } else {
        printf("Matriks M1 bukan matriks jarang\n");
    } 

    nl; printf("PRINTING MATRIKS"); nl;
    printf("M1\n");
    displayMatrix(M1); nl;
    printf("M2\n");
    displayMatrix(M2); nl;

    nl; printf("COPYING"); nl;
    printf("Matriks M1 -> M3"); nl;
    copyMatrix(M1, &M3);
    printf("M3\n");
    displayMatrix(M3); nl;

    nl; printf("TRANSPOSING"); nl;
    printf("Matriks M3"); nl;
    transpose(&M3);
    printf("M3\n");
    displayMatrix(M3); nl;

    nl; printf("DETERMINANT"); nl;
    printf("Determinan Matriks M1: %f", determinant(M1)); nl;
    printf("Determinan Matriks M2: %f", determinant(M2)); nl;
    printf("Determinan Matriks M3: %f", determinant(M3)); nl;

    float exeKiller;
    printf("\n\n(End of Program - Enter non-whitespace character to exit)");
    scanf("%f", &exeKiller); 
    /* for executable file */
    
    return 0;
}