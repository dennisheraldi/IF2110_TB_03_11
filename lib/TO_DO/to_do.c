#include "../../config/initconfig.h"

void displayList()
{
    int length = lengthPrio(antrianPesanan);
    for (int i = 0; i < length; i++)
    {
        Barang temp = antrianPesanan.buffer[i];
        printf("%d. ",(i+1));
        printf("%c -> %c ",PICKUP_LOC(temp),DROPOFF_LOC(temp));

        if (TYPE(temp) == "N")
        {
            printf("(Normal Item)");
        }
        else if (TYPE(temp) == "H")
        {
            printf("(Heavy Item)");
        }
        else if (TYPE(temp) == "P")
        {
            printf("(Perishable Item)");
        }
        printf("\n");
    }
}