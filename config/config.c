#include "initconfig.h"
#include "config.h"


void config() {
    int row, col, i, j, counter, val;
    char c;
    POINT point;
    Bangunan building;
    Barang barang;

    // Konstruktor
    CreateListDin(&buildings, 27);
    CreatePrioQueue(&antrianPesanan);
    CreateListLinked(&antrian);
    CreateListLS(&boughtGadget); // Inisialisasi inventory
    CreateStack(&tas); // Inisialisasi tas
    CreateListLinked(&inProgress); //analog dengan tas
    CreateListLinked(&savedBarang);
    
    time = 0;
    time2 = 0;
    balance = 0;
    pesananSelesai = 0;
    simpingTime = 0;
    returnCounter = 0;
    counterPesanan = 0;

    row = currentToken.val;
    advToken();
    col = currentToken.val;
    CreateMatrix(row, col, &map);
    i = j = 0;
    while (isIdxEffM(map, i, j)) {
        while (isIdxEffM(map, i, j)) {
            ELMT(map, i, j) = -1;
            j++;
        }
        j = 0;
        i++;
    }
    advToken();
    row = currentToken.val;
    advToken();
    col = currentToken.val;

    c = '8';
    point = MakePOINT(row, col);
    NAME(currentPosition) = c;
    LOCATION(currentPosition) = point;
    NAME(HQ) = c;
    LOCATION(HQ) = point;

    // BANGUNAN
    NAME(building) = c;
    LOCATION(building) = point;
    ELMTLD(buildings, 0) = building;
    ELMT(map, row - 1, col - 1) = 8;
    // BANGUNAN DAN MAP
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        val = currentToken.tkn;
        NAME(building) = val;
        advToken();
        row = currentToken.val;
        Absis(LOCATION(building)) = row;
        advToken();
        col = currentToken.val;
        Ordinat(LOCATION(building)) = col;
        // printf("%d", val);
        ELMT(map, row - 1, col - 1) = val;
        CreateQueue(&ANTREAN(building));
        ELMTLD(buildings, i + 1) = building;
    }
    NEFF(buildings) = i + 1;
    compactList(&buildings);

    // ADJACENCY
    CreateMatrix(counter + 1, counter + 1, &adjacency);
    i = j = 0;
    while (isIdxEffM(adjacency, i, j)) {
        while (isIdxEffM(adjacency, i, j)) {
            advToken();
            ELMT(adjacency, i, j) = currentToken.val;
            j++;
        }
        j = 0;
        i++;
    }

    // ANTRIANBARANG
    advToken();
    counter = currentToken.val;
    i = 0;
    for (i = 0; i < counter; i++) {
        advToken();
        ORDER_TIME(barang) = currentToken.val;
        advToken();
        PICKUP_LOC(barang) = currentToken.tkn;
        advToken();
        DROPOFF_LOC(barang) = currentToken.tkn;
        advToken();
        TYPE(barang) = currentToken.tkn;
        if (currentToken.tkn == 'P') {
            advToken();
            EXP_TIME(barang) = currentToken.val;
        }
        enqueuePrio(&antrianPesanan, barang);
        insertLast(&savedBarang, barang);
    }
}