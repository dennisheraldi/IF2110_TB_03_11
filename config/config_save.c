#include "config_save.h"

void save_number(int val) {
    if (val >= 10) {
            adv((char)(val / 10 + 48));
            adv((char)(val % 10 + 48));
        } else {
            adv((char)(val + 48));
        }
}

void config_save() {
    start( true, "SAVED_GAMES/new.txt", true);
    int row, col, i, j, counter, val;
    Barang barang;
    row = ROWS(map);
    col = COLS(map);
    save_number(row);
    adv(' ');
    save_number(col);
    adv('\n');
    val = Absis(LOCATION(HQ));
    save_number(val);
    adv(' ');
    val = Ordinat(LOCATION(HQ));
    save_number(val);
    adv('\n');
    val = lengthLD(buildings) - 1;
    save_number(val);
    adv('\n');
    counter = val + 1;
    for (i = 1; i < counter; i++) {
        adv(NAME(ELMTLD(buildings, i)));
        adv(' ');
        val = Absis(LOCATION(ELMTLD(buildings, i)));
        save_number(val);
        adv(' ');
        val = Ordinat(LOCATION(ELMTLD(buildings, i)));
        save_number(val);
        adv('\n');
    }
    row = ROWS(adjacency);
    col = COLS(adjacency);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            save_number(ELMT(adjacency, i, j));
            if (j != col - 1) {
                adv(' ');
            }
        }
        adv('\n');
    }
    // while (!isEmptyPrio(antrianPesanan)) {
    //     barang = getElmt(savedBarang, i);
    //     save_number(ORDER_TIME(barang));
    //     adv(' ');
    //     adv(PICKUP_LOC(barang));
    //     adv(' ');
    //     adv(DROPOFF_LOC(barang));
    //     adv(' ');
    //     adv(TYPE(barang));
    //     adv(' ');
    //     if (TYPE(barang) == 'P') {
    //         save_number(EXP_TIME(barang));
    //     }
    //     adv('\n');
    // }
    // adv('x');
    close();
}