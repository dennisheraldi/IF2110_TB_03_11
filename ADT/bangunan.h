/* File: bangunan.h */
/* Definisi ADT Bangunan */

#include "point.h"

#ifndef BANGUNAN_H
#define BANGUNAN_H

typedef struct {
    char name[5]; //Nama maksimum terdiri atas 5 karakter
    POINT location;
} Bangunan;

#define NAME(p) (p).name;
#define LOCATION(p) (p).location;

#endif