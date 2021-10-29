#ifndef INIT_CONFIG_H
#define INIT_CONFIG_H


#include <stdio.h>
#include <string.h>
#include "../ADT/boolean.h"
#include "../ADT/bangunan.h"
#include "../ADT/queue.c"
#include "../ADT/prioqueue.c"
#include "../ADT/barang.h"
#include "../ADT/matrix.c"
#include "../ADT/point.c"
#include "../ADT/tokenmachine.c"
#include "../ADT/list.c"
#include "../ADT/listdin.c"


extern int time;
extern int balance;
extern Matrix adjacency;
extern Matrix map;
extern Bangunan currentPosition;
extern Bangunan HQ;
extern List boughtGadget;
extern ListDin buildings;
extern PrioQueue antrianPesanan;
extern char command[20];
extern int commandLen;

#endif