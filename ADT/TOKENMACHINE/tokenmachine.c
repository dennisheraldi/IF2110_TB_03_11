#include <stdio.h>
#include "charmachine.h"
#include "tokenmachine.h"

/*
Nama: David Karel Halomoan
NIM: 13520154
Tanggal : 30 September 2021
Topik Praktikum: ADT Mesin Kata
Deskripsi: File ini berisi ADT mesin token yang memiliki header "tokenmachine.h.h"
*/

/* Token Machine State */
boolean endToken;
Token currentToken;
boolean withFileToken;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
   while (currentChar == BLANK && currentChar != MARK || currentChar == '\n') {
         adv();
   }
}

boolean startToken(boolean file, char filename[])
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
{
    boolean ret;
    ret = start(file, filename);
    if (ret) {
        ignoreBlank();
        if (currentChar == MARK) {
            endToken = true;
        } else {
            endToken = false;
            salinToken();
        }
    }
    return ret;
}

void advToken()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true		  
   Proses : Akuisisi kata menggunakan procedure salinToken */
{
    ignoreBlank();
    if (currentChar == MARK) {
        endToken = true;
    } else {
        salinToken();
        ignoreBlank();
    }
}

void salinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
{
    int i;
    i = 0;
    currentToken.val = 0;
    while (!(currentChar == BLANK || currentChar == MARK) && i < TOKENCAPACITY && currentChar != '\n') {
        if ((currentChar == '0') || (currentChar == '1') || (currentChar == '2') || (currentChar == '3') || (currentChar == '4') || (currentChar == '5') || (currentChar == '6') || (currentChar == '7') || (currentChar == '8') || (currentChar == '9')) {
            switch (currentChar)
            {
                case '1':
                    currentToken.val *= 10;
                    currentToken.val += 1;
                    break;
                case '2':
                    currentToken.val *= 10;
                    currentToken.val += 2;
                    break;
                case '3':
                    currentToken.val *= 10;
                    currentToken.val += 3;
                    break;
                case '4':
                    currentToken.val *= 10;
                    currentToken.val += 4;
                    break;
                case '5':
                    currentToken.val *= 10;
                    currentToken.val += 5;
                    break;
                case '6':
                    currentToken.val *= 10;
                    currentToken.val += 6;
                    break;
                case '7':
                    currentToken.val *= 10;
                    currentToken.val += 7;
                    break;
                case '8':
                    currentToken.val *= 10;
                    currentToken.val += 8;
                    break;
                case '9':
                    currentToken.val *= 10;
                    currentToken.val += 9;
                    break;
                default:
                    currentToken.val *= 10;
                    break;
            }
            currentToken.tkn = 'b';
        } else {
            currentToken.tkn = currentChar;
            currentToken.val = -1;
        }
        adv();
        i++;
    }
}