#include "barang.h"
#include "../IF2110_TB_11_03/config/initconfig.h"

boolean EQBarang(Barang a, Barang b){
    return (ORDER_TIME(a)==ORDER_TIME(b)) && (PICKUP_LOC(a)==PICKUP_LOC(b)) && (DROPOFF_LOC(a)==DROPOFF_LOC(b)) && (TYPE(a)==TYPE(b));
}