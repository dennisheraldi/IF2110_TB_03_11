#ifndef INIT_CONFIG_H
#define INIT_CONFIG_H


#include <stdio.h>
#include <string.h>
#include "../ADT/boolean.h"
#include "../ADT/BANGUNAN/bangunan.h"
#include "../ADT/QUEUE/queue.h"
#include "../ADT/STACK/stack.h"
#include "../ADT/PRIOQUEUE/prioqueue.h"
#include "../ADT/BARANG/barang.h"
#include "../ADT/MATRIX/matrix.h"
#include "../ADT/POINT/point.h"
#include "../ADT/TOKENMACHINE/tokenmachine.h"
#include "../ADT/LIST/list.h"
#include "../ADT/LISTDIN/listdin.h"
#include "../ADT/LIST_LINKED/list_linked.h"
#include "../ADT/PCOLOR/pcolor.h"
#include "../ADT/WORDMACHINE/wordmachine.h"
#include "../ADT/TOKENMACHINE/tokenmachine.h"
#include "../lib/COMMAND_PARSER/commandParser.h"
#include "../lib/STRING_PROCESSOR/string_processor.h"
#include "../lib/BUY/buy.h"
#include "../lib/DROP_OFF/drop_off.h"
#include "../lib/MAP/map.h"
#include "../lib/MOVE/move.h"
#include "../lib/PICK_UP/pickup.h"
#include "../lib/TO_DO/to_do.h"
#include "../lib/HELP/help.h"
#include "../lib/IN_PROGRESS/in_progress.h"
#include "../lib/INVENTORY/inventory.h"


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