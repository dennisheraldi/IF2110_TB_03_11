#include <stdio.h>
#include "../../config/initconfig.h"
// #include "../commandParser/commandParser.h"

void tambahWaktu()
{
    Barang temp, elemen;
    int indeks, i, j;
    if (jumlahHeavyDiTas > 0)
    {
        time += (1 + jumlahHeavyDiTas);
        time2 += (1 + jumlahHeavyDiTas);
    }
    else if (isSpeedBoostActive)
    {
        if (saatnyaTambahWaktu)
        {
            time++; time2++;
            sisaLokasi--;
            saatnyaTambahWaktu = false;
        }
        else
        {
            saatnyaTambahWaktu = true;
            sisaLokasi--;
        }
        if (sisaLokasi == 0)
        {
            isSpeedBoostActive = false;
        }
    } else if (pintuKemanaSaja) {
        pintuKemanaSaja = false;
    }
    else
    {
        time++; time2++;
    }
    //cek apakah ada perishable items yang hangus
    i = 0;
    while (i<length(inProgress))
    {
        elemen = getElmt(inProgress, i);
        if (TYPE(elemen) == 'p')
        {
            if (time >= PICKUP_TIME(elemen) + EXP_TIME(elemen))
            {
                deleteAt(&inProgress, i, &temp);
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    while (!isEmptyS(tas))
    {
        pop(&tas, &temp);
    }
    j = length(inProgress)-1;
    while (j>=0)
    {
        push(&tas, getElmt(inProgress, j));
        j--;
    }
    //cek apakah ada pesanan baru dari antrianPesanan, bila ada tambahkan ke antrian dan enqueue ke masing-masing building
    while ((time >= ORDER_TIME(HEADPRIO(antrianPesanan))) && (!isEmptyPrio(antrianPesanan)))
    {
        dequeuePrio(&antrianPesanan, &temp);
        insertLast(&antrian, temp);
        indeks = indexOfLD(buildings, PICKUP_LOC(temp));
        if (indeks != IDX_UNDEF)
        {
            enqueue(&(ANTREAN(ELMTLD(buildings, indeks))), temp);
        }
    }
}

void move()
{
    //KAMUS
    int i, nomor, j, counter, input;
    boolean found, valid;
    Bangunan reachable[100];
    //ALGORITMA
    //cetak posisi yang dapat dicapai
    printf("Posisi yang dapat dicapai:\n");
    //mendapatkan nomor baris di adjacency matrix
    if (EQ(LOCATION(HQ), LOCATION(currentPosition)))
    {
        nomor = 0;
    }
    else
    {
        i = 0;
        found = false;
        while (!found && isIdxValidLD(buildings, i))
        {
            if (EQ(LOCATION(currentPosition), LOCATION(ELMTLD(buildings, i))))
            {
                found = true;
                nomor = i;
            }
            else
            {
                i++;
            }
        }
    }
    //cek adjacency matrix lalu cetak bila dapat diakses
    j = 0;
    counter = 1;
    for (j = 0; isIdxEffM(adjacency, nomor, j); j++)
    {
        if (ELMT(adjacency, nomor, j) == 1)
        {
            printf("%d. %c ", counter, NAME(ELMTLD(buildings, j)));
            TulisPOINT(LOCATION(ELMTLD(buildings, j)));
            printf("\n");
            reachable[counter - 1] = ELMTLD(buildings, j);
            counter++;
        }
    }
    counter--;
    //meminta input lokasi mana yang ingin dikunjungi
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
    do
    {
        printf("ENTER COMMAND: ");
        getCommand();
        input = command[0] - '0';
        valid = ((input <= counter) && (0 <= input));
        if (!valid)
        {
            printf("Input tidak valid !\n");
        }
    } while (!valid);
    if (input != 0)
    {
        currentPosition = reachable[input - 1];
        tambahWaktu();
        printf("Mobita sekarang berada di titik %c ", NAME(currentPosition));
        TulisPOINT(LOCATION(currentPosition));
        printf("!\n");
    }
}