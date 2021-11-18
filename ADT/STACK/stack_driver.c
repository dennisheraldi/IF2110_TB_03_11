#include <stdio.h>
#include "stack.h"


int main(){

    Barang b;
    Stack tas;
    CreateStack(&tas);

    printf("Waktu Pick Up: "); scanf("%d", &PICKUP_TIME(b));
    printf("Waktu Drop Off: "); scanf("%d", &ORDER_TIME(b));
    printf("Jenis Barang: "); scanf("%s", &TYPE(b));
    printf("Lokasi Pick Up: "); scanf("%s", &PICKUP_LOC(b));
    printf("Lokasi Drop Off: "); scanf("%s", &PICKUP_LOC(b));
    printf("Expired Time: "); scanf("%s", &EXP_TIME(b));

    push(&tas, b);

    printf("[%d,%d,%s,%s,%s,%d]", 
                PICKUP_TIME(TOP(tas)),
                ORDER_TIME(TOP(tas)),
                PICKUP_LOC(TOP(tas)),
                DROPOFF_LOC(TOP(tas)),
                TYPE((TOP(tas))),
                EXP_TIME(TOP(tas)));

}