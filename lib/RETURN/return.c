#include "return.h"

void return_to_sender() {
    Queue q;
    char loc;
    int i, idx, n;
    Barang barang, val;
    Bangunan bangunan;
    if (returnCounter > 0) {
        if (TYPE(TOP(tas)) != 'V') {
            if (!isEmptyS(tas)) {
                returnCounter--;
                pop(&tas, &barang);
                insertLast(&antrian, barang);
                idx = indexOf(inProgress, barang);
                deleteAt(&inProgress, idx, &val);
                loc = PICKUP_LOC(barang);
                idx = indexOfLD(buildings, loc);
                bangunan = ELMTLD(buildings, idx);
                q = ANTREAN(bangunan);
                if (IDX_HEAD(q) == 0) {
                    n = lengthQ(q);
                    for (i = n; i > 0; i++) {
                        q.buffer[i] = q.buffer[i - 1];
                    }
                    q.buffer[0] = barang;
                    IDX_TAIL(q)++;
                } else {
                    IDX_HEAD(q)--;
                    HEAD(q) = barang;
                }
                printf("\nItem teratas pada tas dikembalikan ke tempat semula!\n\n");
            } else {
                printf("\nTas kosong, tidak ada yang bisa dikembalikan!\n\n");
            }
        } else {
            printf("\nBarang VIP tidak dapat dikembalikan!\n\n");
        }
    } else {
        printf("\nAnda tidak mempunyai ability ini!\n\n");
    }
}