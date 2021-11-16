/* File: bangunan.h */
/* Definisi ADT Bangunan */



#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "point.h"
#include "queue.h"

typedef struct {
    char name; //Nama dipastikan satu karakter
    POINT location;
    Queue antrean;
} Bangunan;

#define NAME(p) (p).name
#define LOCATION(p) (p).location
#define ANTREAN(p) (p).antrean

#endif