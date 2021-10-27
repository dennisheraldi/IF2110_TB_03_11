#include <stdio.h>
#include <string.h>
#include "../../config/initconfig.h"
#include "../../ADT/boolean.h"
#include "../../ADT/charmachine.h"

boolean isCommandEqual(char input[]) {
    boolean equal;
    int i, len;
    len = strlen(input);
    equal = (commandLen == len);
    i = 0;
    while (equal && i < len) {
        if (command[i] != input[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

void getCommand() {
// Digunakan untuk mendapatkan input secara manual
    int i;
    i = 0;
    start(false, "x");
    while (!eot && i < 50)
    {
        command[i] = currentChar;
        i++;
        adv();
    }
    commandLen = i;
}   


