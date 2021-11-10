#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

/*
Nama: David Karel Halomoan
NIM: 13520154
Tanggal : 24 September 2021
Topik Praktikum: ADT Mesin Kata
Deskripsi: File ini berisi ADT mesin kata yang memiliki header "wordmachine.h"
*/

/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlankW()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (!(currentChar != BLANK || currentChar == MARK) || currentChar == '\n') {
         adv();
   }
}

void startWord(boolean file, char filename[])
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
   start(file,filename);
   ignoreBlankW();
   if (currentChar == MARK) {
      endWord = true;
   } else {
      endWord = false;
      copyWord();
   }
}

void advWord()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
{
   ignoreBlankW();
   if (currentChar == MARK) {
      endWord = true;
   } else {
      copyWord();
   }
}

void copyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
{
   int i;
   i = 0;
   while (currentChar != BLANK && currentChar != MARK && i < WORDCAPACITY && currentChar != '\n') {
      currentWord.contents[i] = currentChar;
      adv();
      i++;
   }
   currentWord.length = i;
}