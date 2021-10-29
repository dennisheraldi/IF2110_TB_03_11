#include <stdio.h>
#include "../../ADT/pcolor.h"
#include "../../ADT/matrix.h"
#include "../../ADT/point.h"
#include "../../ADT/bangunan.h"
#include "../../ADT/barang.h"
#include "../../config/initconfig.h"

void displayMap()
{
    for (int i = 0; i < ROWS(map) + 2; i++)
    {
        for (int j = 0; j < COLS(map) + 2; j++)
        {
            POINT temp = MakePOINT(i,j);
            if (EQ(currentPosition,temp))
            {
                print_yellow(""); // nanti diisi
            }
            else if (EQ(HQ,temp))
            {
                printf("8");
            }
            else if (i == 0 || i == (ROWS(map) + 1) || j == 0 || j == (COLS(map) + 1))
            {
                printf("*");
            }
            // masih banyak yg kurang ntar ditambahin pas config udah selesai
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    printf("Mobita berada di posisi A"); //nanti A diganti karakter yg sesuai
    TulisPOINT(currentPosition);
    printf("Waktu: %d",time);
    printf("Uang yang dimiliki: %d",jumlah_uang);
    printf("Jumlah pesanan yang dikerjakan: %d",jumlah_pesanan); // length pesanan hasil config

}
