#include <stdio.h>
#include "../../ADT/wordmachine.h"
#include "../../config/initconfig.h"

Word concatenate(Word w1, Word w2) {
    Word w;
    int i, j;
    for (i = 0; i < w1.length; i++) {
        w.contents[i] = w1.contents[i];
    }
    for (j = 0; j < w2.length; j++) {
        w.contents[i] = w2.contents[j];
        i++;
    }
    w.length = w1.length + w2.length;
    return w;
}

void wordToString(Word w, char * str) {
    int i;
    for (i = 0; i < w.length; i++) {
        str[i] = w.contents[i];
    }
    str[w.length] = '\0';
}