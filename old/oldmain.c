
#include <stdio.h>
#include "oldlexer.h"



int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("uhh where is the .prll file...?\n");
        return 1;
    }

    char code[4096];
    FILE *protogenfile = fopen(argv[1], "r");
    int pointer = 0;
    int fuckinchar;
    while ((fuckinchar = fgetc(protogenfile)) != EOF && pointer < 4095) {
        code[pointer] = fuckinchar;
        pointer++;
        //printf("%c", fuckinchar);
    }
    code[pointer] = '\0';
    fclose(protogenfile);

    //printf("code: %s\n", code);

    lexer(code);
    

    //char cmd[20] = "sajy hi";
    //lexer(cmd);
    /*char cmd2[20] = "helloi say";
    lexer(cmd2);*/
    return 0;
}