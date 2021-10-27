#include <stdio.h>
#include <string.h>
#include "../../config/initconfig.h"
#include "../../ADT/boolean.h"
#include "../../ADT/charmachine.h"

boolean isCommandEqual(char input[]) {
    boolean equal;
    int i;
    equal = (commandLen == strlen(input));
    i = 0;
    while (equal && i < strlen(input)) {
        if (command[i] != input[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean getCommand() {
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


