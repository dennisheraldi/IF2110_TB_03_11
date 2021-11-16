#include "boolean.h"

#ifndef BARANG_H
#define BARANG_H

typedef struct{
    int waktu_pickup;
    int waktu_order;
    char lokasi_pickup;
    char lokasi_dropoff;
    char jenis_barang; // perishable/normal/heavy
    int waktu_expired; // khusus untuk perishable item 
}Barang;

#define PICKUP_TIME(b) (b).waktu_pickup
#define ORDER_TIME(b) (b).waktu_order
#define PICKUP_LOC(b) (b).lokasi_pickup
#define DROPOFF_LOC(b) (b).lokasi_dropoff
#define TYPE(b) (b).jenis_barang
#define EXP_TIME(b) (b).waktu_expired

boolean EQBarang(Barang a, Barang b);

#endif
