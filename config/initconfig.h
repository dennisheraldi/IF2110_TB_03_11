#ifndef INIT_CONFIG_H
#define INIT_CONFIG_H


#include <stdio.h>
#include <string.h>
#include "../ADT/boolean.h"
#include "../ADT/bangunan.h"
#include "../ADT/queue.h"
#include "../ADT/stack.h"
#include "../ADT/prioqueue.h"
#include "../ADT/barang.h"
#include "../ADT/matrix.h"
#include "../ADT/point.h"
#include "../ADT/tokenmachine.h"
#include "../ADT/list.h"
#include "../ADT/listdin.h"
#include "../ADT/list_linked.h"
#include "../ADT/pcolor.h"
#include "../lib/BUY/buy.h"
#include "../lib/DROP_OFF/drop_off.h"
#include "../lib/MAP/map.h"
#include "../lib/MOVE/move.h"
#include "../lib/PICK_UP/pickup.h"
#include "../lib/TO_DO/to_do.h"

extern int time;
extern int balance;
extern Stack tas;
extern Matrix adjacency;
extern Matrix map;
extern Bangunan currentPosition;
extern Bangunan HQ;
extern List boughtGadget;
extern ListDin buildings;
extern PrioQueue antrianPesanan;
extern ListLinked antrian; // ini buat TO_DO dan IN_PROGRESS
extern char command[20];
extern int commandLen;
extern int jumlahHeavyDiTas;
extern boolean saatnyaTambahWaktu;
extern boolean isSpeedBoostActive;
extern int sisaLokasi;
extern ListLinked inProgress;

#endif