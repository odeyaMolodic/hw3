#include <stdio.h>
#include "strings.h"
#define WORD 30

int main() {
    char strToFind[WORD];
    char func;
    getword(strToFind);

    scanf(" %c", &func);
    char c;
    scanf(" %c", &c); //c == '\n'
    scanf(" %c", &c);
    if(func=='a')
        print_lines(strToFind);
    else if(func=='b')
        print_similar_words(strToFind);
    else 
        return 0;
    return 1;
}
