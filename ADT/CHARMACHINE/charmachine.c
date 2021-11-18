/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean eot;
boolean withFile;
boolean saveMode;

static FILE * tape;
static int retval;


boolean start(boolean file, char filename[], boolean save) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
       saveMode = save;
       withFile = file;
       if (!saveMode) {
              if (withFile) {
                     tape = fopen(filename, "r");
              } else {
                     tape = stdin;
              }

              if (!withFile || tape != NULL) {
                     adv('c');
              }
       } else {
              tape = fopen(filename, "w");
       }
       return !withFile || tape != NULL || saveMode;
}

void adv(char character) {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
	   Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
       if (!saveMode) {
              retval = fscanf(tape,"%c",&currentChar);
              if (withFile) {
                     eot = (retval == EOF);
              } else {
                     eot = (currentChar == '\n');
              }
              if (eot && withFile) {
                     fclose(tape);
              }
       } else {
              fprintf(tape, "%c", character);
       }
}

void close() {
       if (tape != NULL) {
              fclose(tape);
       }
       saveMode = false;
}
