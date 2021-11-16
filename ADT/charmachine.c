/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>
#include <string.h>

char currentChar;
boolean eot;
boolean withFile;

static FILE * tape;
static int retval;


boolean start(boolean file, char filename[]) {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
       withFile = file;
       if (withFile) {
              tape = fopen(filename, "r");
       } else {
	       tape = stdin;
       }

       if (!withFile || tape != NULL) {
	       adv();
       }
       
       return !withFile || tape != NULL;
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
	   Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	retval = fscanf(tape,"%c",&currentChar);
       if (withFile) {
	       eot = (retval == EOF);
       } else {
              eot = (currentChar == '\n');
       }
	if (eot && withFile) {
              fclose(tape);
 	}
}
