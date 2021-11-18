#include "config_save.h"

void save_number(int val) {
    if (val >= 10000) {
        adv((char)(val / 10000 + 48));
        adv((char)((val % 10000) / 1000 + 48));
        adv((char)((val % 1000) / 100 + 48));
        adv((char)((val % 100) / 10 + 48));
        adv((char)(val % 10 + 48));
    } else if (val >= 1000) {
        adv((char)(val / 1000 + 48));
        adv((char)((val % 1000) / 100 + 48));
        adv((char)((val % 100) / 10 + 48));
        adv((char)(val % 10 + 48));
    }else if (val >= 100) {
        adv((char)(val / 100 + 48));
        adv((char)((val % 100) / 10 + 48));
        adv((char)(val % 10 + 48));
    }else if (val >= 10) {
        adv((char)(val / 10 + 48));
        adv((char)(val % 10 + 48));
    } else {
        adv((char)(val + 48));
    }
}

void config_save() {
    Word inputName, dir, fileName;
    ListLinked listBarang;
    int row, col, i, j, counter, val;
    Barang barang;

    dir.contents[0] = 'S';
    dir.contents[1] = 'A';
    dir.contents[2] = 'V';
    dir.contents[3] = 'E';
    dir.contents[4] = 'D';
    dir.contents[5] = '_';
    dir.contents[6] = 'G';
    dir.contents[7] = 'A';
    dir.contents[8] = 'M';
    dir.contents[9] = 'E';
    dir.contents[10] = 'S';
    dir.contents[11] = '/';
    dir.length = 12;
    inputName = commandToWord();
    char str[inputName.length + dir.length + 10];
    fileName = concatenate(dir, inputName);
    wordToString(fileName, str);

    start(true, str, true);

    CreateListLinked(&listBarang);

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
    save_number(length(savedBarang));
    adv('\n');
    for (i = 0; i < length(savedBarang); i++) {
        barang = getElmt(savedBarang, i);
        save_number(ORDER_TIME(barang));
        adv(' ');
        adv(PICKUP_LOC(barang));
        adv(' ');
        adv(DROPOFF_LOC(barang));
        adv(' ');
        adv(TYPE(barang));
        adv(' ');
        if (TYPE(barang) == 'P') {
            save_number(EXP_TIME(barang));
        }
        adv('\n');
    }
    save_number(time);
    adv('\n');
    save_number(time2);
    adv('\n');
    save_number(balance);
    adv('\n');
    save_number(pesananSelesai);
    adv('\n');
    adv(NAME(currentPosition));
    adv(' ');
    save_number(Absis(LOCATION(currentPosition)));
    adv(' ');
    save_number(Ordinat(LOCATION(currentPosition)));
    adv('\n');
    while (!isEmptyS(tas))
    {
        pop(&tas, &barang);
        insertFirst(&listBarang, barang);
    }
    counter = length(listBarang);
    save_number(counter);
    adv('\n');
    for (i = 0; i < counter; i++) {
        save_number(ORDER_TIME(getElmt(listBarang, i)));
        adv(' ');
        adv(PICKUP_LOC(getElmt(listBarang, i)));
        adv(' ');
        adv(DROPOFF_LOC(getElmt(listBarang, i)));
        adv(' ');
        adv(TYPE(getElmt(listBarang, i)));
        adv(' ');
        if (TYPE(getElmt(listBarang, i)) == 'V') {
            save_number(EXP_TIME(getElmt(listBarang, i)));
            adv(' ');
        }
        save_number(PICKUP_TIME(getElmt(listBarang, i)));
        adv('\n');
    }
    for (i = 0; i < counter; i++) {
        push(&tas, getElmt(listBarang, i));
    }
    while (!isEmpty(listBarang)) {
        deleteFirst(&listBarang, &barang);
    }
    while (!isEmptyPrio(antrianPesanan))
    {
        dequeuePrio(&antrianPesanan, &barang);
        insertLast(&listBarang, barang);
    }
    counter = length(listBarang);
    save_number(counter);
    adv('\n');
    for (i = 0; i < counter; i++) {
        save_number(ORDER_TIME(getElmt(listBarang, i)));
        adv(' ');
        adv(PICKUP_LOC(getElmt(listBarang, i)));
        adv(' ');
        adv(DROPOFF_LOC(getElmt(listBarang, i)));
        adv(' ');
        adv(TYPE(getElmt(listBarang, i)));
        if (TYPE(getElmt(listBarang, i)) == 'V') {
            adv(' ');
            save_number(EXP_TIME(getElmt(listBarang, i)));
        }
        adv('\n');
    }
    for (i = 0; i < counter; i++) {
        enqueuePrio(&antrianPesanan, getElmt(listBarang, i));
    }
    save_number(jumlahHeavyDiTas);
    adv('\n');
    if (saatnyaTambahWaktu) {
        adv('t');
    } else {
        adv('f');
    }
    adv('\n');
    if (isSpeedBoostActive) {
        adv('t');
    } else {
        adv('f');
    }
    adv('\n');
    if (pintuKemanaSaja) {
        adv('t');
    } else {
        adv('f');
    }
    adv('\n');
    if (senterPengecil) {
        adv('t');
    } else {
        adv('f');
    }
    adv('\n');
    save_number(sisaLokasi);
    adv('\n');
    counter = length(inProgress);
    save_number(counter);
    adv('\n');
    for (i = 0; i < counter; i++) {
        save_number(ORDER_TIME(getElmt(inProgress, i)));
        adv(' ');
        adv(PICKUP_LOC(getElmt(inProgress, i)));
        adv(' ');
        adv(DROPOFF_LOC(getElmt(inProgress, i)));
        adv(' ');
        adv(TYPE(getElmt(inProgress, i)));
        adv(' ');
        if (TYPE(getElmt(inProgress, i)) == 'V') {
            save_number(EXP_TIME(getElmt(inProgress, i)));
            adv(' ');
        }
        save_number(PICKUP_TIME(getElmt(inProgress, i)));
        adv('\n');
    }
    counter = NEFF(boughtGadget);
    save_number(counter);
    adv('\n');
    for (i = 0; i < counter; i++) {
        save_number(ELMTLS(boughtGadget, i));
        adv('\n');
    }
    counter = length(antrian);
    save_number(counter);
    adv('\n');
    for (i = 0; i < counter; i++) {
        save_number(ORDER_TIME(getElmt(antrian, i)));
        adv(' ');
        adv(PICKUP_LOC(getElmt(antrian, i)));
        adv(' ');
        adv(DROPOFF_LOC(getElmt(antrian, i)));
        adv(' ');
        adv(TYPE(getElmt(antrian, i)));
        if (TYPE(getElmt(antrian, i)) == 'V') {
            adv(' ');
            save_number(EXP_TIME(getElmt(antrian, i)));
        }
        adv('\n');
    }
    save_number(simpingTime);
    adv('\n');
    save_number(returnCounter);
    adv('\n');
    close();
}