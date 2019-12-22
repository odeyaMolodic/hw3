#include <stdio.h>
#define LINE 256
#define WORD 30

int getlinee(char s[]) {
    int count = 0;
    for(int i=0; i<LINE; i++){
        count += scanf(" %c",s+i);
        if(s[i] == '\n') {
            s[i+1] = '\0';
            return count;
        }
        if(s[i] == EOF)
            return EOF;
    }
    return count; //error
}

int getword(char w[]) {
    int count = 0;
    for(int i=0; i<WORD; i++){
        count += scanf(" %c",w+i);
        if(w[i] == ' ' || w[i] == '\t' || w[i] == '\n') {
            w[i+1] = '\0';
            return count;
        }
        if(w[i] == EOF)
            return EOF;
    }
    return count; //error
}

int substring(char *str1, char *str2) {
    int j = 0;
    int tempI, tempJ;
    for(int i=0; str2[i]!=0 && i<sizeof(str2); i++) {
        while(str1[j]) {
            if(str2[i]==str1[j]) {
                tempI = i+1;
                tempJ = j+1;
                int flag = 1;
                while(str2[tempI] && flag) {
                    if (str2[tempI]!=str1[tempJ])
                        flag = 0;
                    tempI++;
                    tempJ++;
                }
                if(flag) 
                    return 1;
            }
            j++;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n) {
    int count=0;
    int j=0;
    for(int i=0; t[i]!=0 && i<sizeof(t); i++){
        if(s[j]){
            if(t[i]==s[j]) {
                j++;
                continue;
            }
            count++;
            if (count>n) return 0;
            j++;
        }else 
            return 0;
    }
    return 1;
}

void print_lines(char *str) {
    char line[LINE];
    while(getlinee(line)!=EOF && substring(line, str)){
        printf("%s", line);
    }
    return;
}

void print_similar_words(char *str) {
    char word[WORD];
    while(getword(word)!=EOF && similar(word, str, 1)){
        printf("%s", word);
    }
    return;
}