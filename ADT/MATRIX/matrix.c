#include <stdio.h>
#include "matrix.h"
/*
Nama    : David Karel Halomoan
NIM     : 13520154
*/

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValidM(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
{
    return i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP;
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return ROWS(m) - 1;
}
Index getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return COLS(m) - 1;
}
boolean isIdxEffM(Matrix m, Index i, Index j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return i >= 0 && i < ROWS(m) && j >= 0 && j < COLS(m);
}
ElType getElmtDiagonal(Matrix m, Index i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    int i, j;
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for (i = 0; i < ROWS(mIn); i++) {
        for (j = 0; j < COLS(mIn); j++) {
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    int i, j;
    CreateMatrix(nRow, nCol, m);
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    int i, j;
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            printf("%d", ELMT(m, i, j));
            if(j != COLS(m) - 1) {
                printf(" ");
            }
        }
        if (i != ROWS(m) - 1) {
            printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Matrix m;
    int i, j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Matrix m;
    int i, j;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    for (i = 0; i < ROWS(m); i++) {
        for (j = 0; j < COLS(m); j++) {
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Matrix m;
    int i, j, k;
    CreateMatrix(ROWS(m1), COLS(m2), &m);
    for (i = 0; i < ROWS(m1); i++) {
        for (j = 0; j < COLS(m2); j++) {
            ELMT(m, i, j) = 0;
            for (k = 0; k < COLS(m1); k++) {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}
Matrix multiplyConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Matrix matrix;
    int i, j;
    CreateMatrix(ROWS(m), COLS(m), &matrix);
    for (i = 0; i < ROWS(matrix); i++) {
        for (j = 0; j < COLS(matrix); j++) {
            ELMT(matrix, i, j) = ELMT(m, i, j) * x;
        }
    }
    return matrix;
}
void pMultiplyConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    int i, j;
    for (i = 0; i < ROWS(*m); i++) {
        for (j = 0; j < COLS(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    boolean sama;
    int i, j;
    sama = isSizeEqual(m1, m2);
    i = 0;
    while (sama && i < ROWS(m1)) {
        j = 0;
        while(sama && isIdxEffM(m1, i, j)) {
            sama = ELMT(m1, i, j) == ELMT(m2, i, j);
            j++;
        }
        i++;
    }
    return sama;
}
boolean isNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return !isEqual(m1, m2);
}
boolean isSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
{
    return ROWS(m1) == ROWS(m2) && COLS(m1) == COLS(m2);
}

/* ********** Operasi lain ********** */
int count(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return ROWS(m) * COLS(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return ROWS(m) == COLS(m);
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    int i, j;
    boolean simetris;
    simetris = isSquare(m);
    i = 0;
    while (simetris && i < ROWS(m)) {
        j = 0;
        while (simetris && j < i) {
            simetris = ELMT(m, i, j) == ELMT(m, j, i);
            j++;
        }
        i++;
    }
    return simetris;
}
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    int i, j;
    boolean identitas;
    identitas = isSquare(m);
    i = 0;
    while (identitas && i < ROWS(m)) {
        j = 0;
        while (identitas && j < i) {
            identitas = (i == j && ELMT(m, i, j) == 1) || (i != j && ELMT(m, i, j) == 0);
            j++;
        }
        i++;
    }
    return identitas;
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    double countNonZero;
    int i, j;
    countNonZero = 0;
    i = 0;
    while (countNonZero / count(m) <= 0.05 && i < ROWS(m)) {
        j = 0;
        while (countNonZero / count(m) <= 0.05 && j < COLS(m)) {
            if (ELMT(m, i, j) != 0) {
                countNonZero += 1;
            }
            j++;
        }
        i++;
    }
    return countNonZero / count(m) <= 0.05;
}
Matrix inverse1(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return multiplyConst(m, -1);
}
void pInverse1(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    pMultiplyConst(m, -1);
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    int i, j, k, baris;
    float determinan;
    Matrix matrix;
    if (ROWS(m) == 1) {
        return ELMT(m, 0, 0);
    } else if (ROWS(m) == 2) {
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);
    } else {
        determinan = 0;
        for (int k = 0; k < ROWS(m); k++) {
            CreateMatrix(ROWS(m) - 1, COLS(m) - 1, &matrix);
            baris = 0;
            for (int i = 0; i < ROWS(m); i++) {
                for (int j = 1; j < COLS(m); j++) {
                    if (i != k) {
                        ELMT(matrix, baris, j - 1) = ELMT(m, i, j);
                    }
                }
                if (i != k) {
                    baris++;
                }
            }
            if ((k + 2) % 2 == 0) {
                determinan += ELMT(m, k, 0) * determinant(matrix);
            } else {
                determinan -= ELMT(m, k, 0) * determinant(matrix);
            }
        }
        return determinan;
    }
}
void transpose(Matrix *m)
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    Matrix matrix;
    CreateMatrix(ROWS(*m), COLS(*m), &matrix);
    copyMatrix(*m, &matrix);
    for (int i = 0; i < ROWS(*m); i++) {
            for (int j = 0; j < COLS(*m); j++) {
                ELMT(*m, i, j) = ELMT(matrix, j, i);
            }
        }
}
