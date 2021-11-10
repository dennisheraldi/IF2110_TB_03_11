//#include <stdio.h>
//#include "../../ADT/pcolor.h"
#include "../../config/initconfig.h"

void displayMap()
{
    int building_idx = 1;
    for (int i = 0; i < ROWS(map) + 2; i++)
    {
        for (int j = 0; j < COLS(map) + 2; j++)
        {
            Bangunan building = ELMTLD(buildings,building_idx);
            POINT temp = MakePOINT(i,j);
            if (EQ(LOCATION(currentPosition),temp))
            {
                print_yellow(NAME(currentPosition)); 
            }
            else if (EQ(LOCATION(HQ),temp))
            {
                printf("8");
            }
            else if (i == 0 || i == (ROWS(map) + 1) || j == 0 || j == (COLS(map) + 1))
            {
                printf("*");
            }
            else if (EQ(LOCATION(building),temp))
            {
                if (NAME(building) == DROPOFF_LOC(HEADPRIO(antrianPesanan)))
                {
                    print_blue(NAME(building));
                }
                else if (NAME(building) == PICKUP_LOC(HEADPRIO(antrianPesanan)))
                {
                    print_red(NAME(building));
                }
                // belum ada kasus yang warna hijau (lokasi yang dapat dicapai)
                else
                {
                    printf("%c",NAME(building));
                }
                building_idx++;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    
}
