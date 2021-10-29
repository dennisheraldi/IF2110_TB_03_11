/* File: bangunan.h */
/* Definisi ADT Bangunan */

#include "point.h"

#ifndef BANGUNAN_H
#define BANGUNAN_H

typedef struct {
    char name; //Nama dipastikan satu karakter
    POINT location;
    Queue antrean;
} Bangunan;

#define NAME(p) (p).name;
#define LOCATION(p) (p).location;
#define ANTREAN(p) (p).antrean;

#endif