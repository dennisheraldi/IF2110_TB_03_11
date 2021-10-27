#include <stdio.h>
#include "../../config/initconfig.h"
#include "../../ADT/boolean.h"
boolean isWordNEW_GAME() {
    boolean equal;
    int i;
    char NEW_GAME[] = "NEW GAME";
    equal = (commandLen == 8);
    i = 0;
    while (equal && i < 8) {
        if (command[i] != NEW_GAME[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordLOAD_GAME() {
    boolean equal;
    int i;
    char LOAD_GAME[] = "LOAD GAME";
    equal = (commandLen == 9);
    i = 0;
    while (equal && i < 9) {
        if (command[i] != LOAD_GAME[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordEXIT() {
    boolean equal;
    int i;
    char EXIT[] = "EXIT";
    equal = (commandLen == 4);
    i = 0;
    while (equal && i < 4) {
        if (command[i] != EXIT[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordMOVE() {
    boolean equal;
    int i;
    char MOVE[] = "MOVE";
    equal = (commandLen == 4);
    i = 0;
    while (equal && i < 4) {
        if (command[i] != MOVE[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordPICK_UP() {
    boolean equal;
    int i;
    char PICK_UP[] = "PICK_UP";
    equal = (commandLen == 7);
    i = 0;
    while (equal && i < 7) {
        if (command[i] != PICK_UP[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordDROP_OFF() {
    boolean equal;
    int i;
    char DROP_OFF[] = "DROP_OFF";
    equal = (commandLen == 8);
    i = 0;
    while (equal && i < 8) {
        if (command[i] != DROP_OFF[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordMAP() {
    boolean equal;
    int i;
    char MAP[] = "MAP";
    equal = (commandLen == 3);
    i = 0;
    while (equal && i < 3) {
        if (command[i] != MAP[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordTO_DO() {
    boolean equal;
    int i;
    char TO_DO[] = "TO_DO";
    equal = (commandLen == 5);
    i = 0;
    while (equal && i < 5) {
        if (command[i] != TO_DO[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordIN_PROGRESS() {
    boolean equal;
    int i;
    char IN_PROGRESS[] = "IN_PROGRESS";
    equal = (commandLen == 11);
    i = 0;
    while (equal && i < 11) {
        if (command[i] != IN_PROGRESS[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordBUY() {
    boolean equal;
    int i;
    char BUY[] = "BUY";
    equal = (commandLen == 3);
    i = 0;
    while (equal && i < 3) {
        if (command[i] != BUY[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordINVENTORY() {
    boolean equal;
    int i;
    char INVENTORY[] = "INVENTORY";
    equal = (commandLen == 9);
    i = 0;
    while (equal && i < 9) {
        if (command[i] != INVENTORY[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordHELP() {
    boolean equal;
    int i;
    char HELP[] = "HELP";
    equal = (commandLen == 4);
    i = 0;
    while (equal && i < 4) {
        if (command[i] != HELP[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordSAVE_GAME() {
    boolean equal;
    int i;
    char SAVE_GAME[] = "SAVE_GAME";
    equal = (commandLen == 9);
    i = 0;
    while (equal && i < 9) {
        if (command[i] != SAVE_GAME[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

boolean isWordRETURN() {
    boolean equal;
    int i;
    char RETURN[] = "RETURN";
    equal = (commandLen == 6);
    i = 0;
    while (equal && i < 6) {
        if (command[i] != RETURN[i]) {
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
    while (!eot)
    {
        command[i] = currentChar;
        i++;
        adv();
    }
    commandLen = i;
}   


