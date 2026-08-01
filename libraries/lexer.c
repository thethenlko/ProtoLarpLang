#include <stdio.h>
#include "lexer.h"
#include "parser.h"

void lexer(char cmd[]) {
    char word[800];
    int i = 0;
    int point = 0;

    for (i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == ' ' || cmd[i] == '\n') {
            word[point] = '\0';
            parser(word, point);
            //printf("%s\n", word);
            point = 0;
        } else {
            word[point] = cmd[i];
            point++;
        }
    }
    word[point] = '\0';
    parser(word, point);
    //printf("%s\n", word);
    point = 0;
    
}