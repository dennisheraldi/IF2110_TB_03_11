#include <stdio.h>
#include "charmachine.c"

char currentChar;
boolean eot;
boolean withFile;
boolean saveMode;

int main() {
    // Cara compile : gcc charmachine.h charmachine_driver.c -o driver, lalu ./driver
    start(true, "read.txt", false);
    while (!eot)
    {
        printf("%c", currentChar);
        adv('x');
    }
    start(true, "write.txt", true);
    adv('W'); adv('R'); adv('I'); adv('T'); adv('E'); adv('\n');
    close();


    return 0;
}