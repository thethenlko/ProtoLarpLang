#include <stdio.h>
#include "lexer.h"
#include "parser.h"

void lexer(char cmd[]) {
    char word[800];
    int i = 0;
    int point = 0;
    
    for (i = 0; cmd[i] != '\0'; i++) {
            
        if (cmd[i] == '~') {
            word[point] = cmd[i];
            i++;
            point++;
            while (cmd[i] != ' ' && cmd[i] != '\n' && cmd[i] != '\0'){
                word[point] = cmd[i];
                point++;
                i++;
            }
            word[point] = '\0';
            parser(word, point);
            point = 0;
            continue;
        }

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