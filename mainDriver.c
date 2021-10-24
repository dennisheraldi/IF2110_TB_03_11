#include <stdio.h>
#include "config/initconfig.h"
#include "config/config.c"
#include "ADT/matrix.c"
#include "ADT/point.h"

int time;
Matrix map;
Matrix adjacency;
POINT currentPosition;


int main() {
    config();
    displayMap(map);
    printf("\n");
    displayMatrix(adjacency);
    printf("\ntime = %d\n", time);
    if (isWordMOVE()) {

    }
    return 0;
}