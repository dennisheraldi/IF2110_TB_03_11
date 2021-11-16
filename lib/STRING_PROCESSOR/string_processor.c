#include "string_processor.h"

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

Word commandToWord() {
    Word w;
    int i;
    for (i = 0; i < commandLen; i++) {
        w.contents[i] = command[i];
    }
    w.length = commandLen;
    return w;
}

void wordToString(Word w, char str[]) {
    int i;
    for (i = 0; i < w.length; i++) {
        str[i] = w.contents[i];
    }
    str[w.length] = '\0';
}

boolean validateFileName() {
    Word inputName, dir, fileName;
    dir.contents[0] = 'n';
    dir.contents[1] = 'e';
    dir.contents[2] = 'w';
    dir.contents[3] = 'G';
    dir.contents[4] = 'a';
    dir.contents[5] = 'm';
    dir.contents[6] = 'e';
    dir.contents[7] = 's';
    dir.contents[8] = '/';
    dir.length = 9;
    inputName = commandToWord();
    char str[inputName.length + dir.length + 10];
    fileName = concatenate(dir, inputName);
    wordToString(fileName, str);
    return startToken(true, str);
}

void printWord(Word w) {
    int i;
    for (i = 0; i < w.length; i++) {
        printf("%c", w.contents[i]);
    }
    printf("\n");
}

void printStringRed(char str[]) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        print_red(str[i]);
        i++;
    }
}

void printStringGreen(char str[]) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        print_green(str[i]);
        i++;
    }
}

void printStringYellow(char str[]) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        print_yellow(str[i]);
        i++;
    }
}

void printStringBlue(char str[]) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        print_blue(str[i]);
        i++;
    }
}

void printStringMagenta(char str[]) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        print_magenta(str[i]);
        i++;
    }
}

void printStringCyan(char str[]) {
    int i;
    i = 0;
    while (str[i] != '\0') {
        print_cyan(str[i]);
        i++;
    }
}