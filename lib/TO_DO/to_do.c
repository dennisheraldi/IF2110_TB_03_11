#include "../../config/initconfig.h"

void displayList()
{
    int length = lengthPrio(antrianPesanan);
    Address p = FIRST(antrian);
    int count = 0;
    while (p != NULL)
    {
        Barang temp = INFO(p);
        printf("%d. ",(count+1));
        printf("%c -> %c ",PICKUP_LOC(temp),DROPOFF_LOC(temp));

        if (TYPE(temp) == 'N')
        {
            printf("(Normal Item)");
        }
        else if (TYPE(temp) == 'H')
        {
            printf("(Heavy Item)");
        }
        else if (TYPE(temp) == 'P')
        {
            printf("(Perishable Item)");
        }
        printf("\n");
        p = NEXT(p);
    }
}