#include "config_load.h"

void config_load() {
    int i, j, row, col, counter, val;
    Barang barang;
    Bangunan bangunan;
    config();
    advToken();
    time = currentToken.val;
    advToken();
    time2 = currentToken.val;
    advToken();
    balance = currentToken.val;
    advToken();
    pesananSelesai = currentToken.val;
    advToken();
    NAME(currentPosition) = currentToken.tkn;
    advToken();
    Absis(LOCATION(currentPosition)) = currentToken.val;
    advToken();
    Ordinat(LOCATION(currentPosition)) = currentToken.val;
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        ORDER_TIME(barang) = currentToken.val;
        advToken();
        PICKUP_LOC(barang) = currentToken.tkn;
        advToken();
        DROPOFF_LOC(barang) = currentToken.tkn;
        advToken();
        TYPE(barang) = currentToken.tkn;
        if (currentToken.tkn == 'V') {
            advToken();
            EXP_TIME(barang) = currentToken.val;
        }
        advToken();
        PICKUP_TIME(barang) = currentToken.val;
        push(&tas, barang);
    }
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        ORDER_TIME(barang) = currentToken.val;
        advToken();
        PICKUP_LOC(barang) = currentToken.tkn;
        advToken();
        DROPOFF_LOC(barang) = currentToken.tkn;
        advToken();
        TYPE(barang) = currentToken.tkn;
        if (currentToken.tkn == 'V') {
            advToken();
            EXP_TIME(barang) = currentToken.val;
        }
        enqueuePrio(&antrianPesanan, barang);
    }
    advToken();
    jumlahHeavyDiTas = currentToken.val;
    advToken();
    saatnyaTambahWaktu = currentToken.tkn =='t';
    advToken();
    isSpeedBoostActive = currentToken.tkn =='t';
    advToken();
    pintuKemanaSaja = currentToken.tkn =='t';
    advToken();
    senterPengecil = currentToken.tkn =='t';
    advToken();
    sisaLokasi = currentToken.val;
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        ORDER_TIME(barang) = currentToken.val;
        advToken();
        PICKUP_LOC(barang) = currentToken.tkn;
        advToken();
        DROPOFF_LOC(barang) = currentToken.tkn;
        advToken();
        TYPE(barang) = currentToken.tkn;
        if (currentToken.tkn == 'V') {
            advToken();
            EXP_TIME(barang) = currentToken.val;
        }
        advToken();
        PICKUP_TIME(barang) = currentToken.val;
        insertLast(&inProgress, barang);
    }
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        ELMTLS(boughtGadget, i) = currentToken.val;
    }
    NEFF(boughtGadget) = counter;
    advToken();
    counter = currentToken.val;
    for (i = 0; i < counter; i++) {
        advToken();
        ORDER_TIME(barang) = currentToken.val;
        advToken();
        PICKUP_LOC(barang) = currentToken.tkn;
        advToken();
        DROPOFF_LOC(barang) = currentToken.tkn;
        advToken();
        TYPE(barang) = currentToken.tkn;
        if (currentToken.tkn == 'V') {
            advToken();
            EXP_TIME(barang) = currentToken.val;
            printf("%d\n", currentToken.val);
        }
        insertLast(&antrian, barang);
    }
    advToken();
    simpingTime = currentToken.val;
    advToken();
    returnCounter = currentToken.val;
    close();
}