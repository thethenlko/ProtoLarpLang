#include "lexer.h"
#include "isSame.h"
#include <stdio.h>
#include <stdbool.h>

char endsymbol[5] = "OwO";
bool isEnd = false;

// ikr its a mess but i am beginner :3
char tcmd[50]; //temp. (i forgot the full word) command
char targs[50]; //temp. (i forgot the full word again yes) arguments
int tpointer = 0; //temp. (i forgot) pointer for arguments
bool debug = false; // to debug ts
bool fuckinerror = false; // if error


void classify(char word[], int point) {
    if (point > 0 && !fuckinerror) {
        if (issame(word, "say")) {
            tcmd[0] = 's';
            if (debug) {
                printf("command: %s\n", tcmd);
            }
        } else {
            if (issame(word, endsymbol)) {
                isEnd = true;

                if (debug) {
                    printf("end\n");
                }

            }
            // i fucking hate this part but this shit is working???
            if (!isEnd) {
                if (tcmd[0] == 's' && tpointer < 49) {
                    for (int i = 0; word[i] != '\0' && i < 49; i++) {
                        targs[tpointer] = word[i];
                        //printf("arg is %s\n", targs);
                        tpointer++;
                        //printf("pointer: %d\n", tpointer);
                    }
                    targs[tpointer] = ' ';
                    tpointer++;

                    targs[tpointer] = '\0';

                    if (debug) {
                        printf("args: %s\n", targs);
                    }
                    return;
                }
            }
            if (isEnd) {
                if (debug) {
                    printf("end function\n");
                    printf("current command: %s\n", tcmd);
                    printf("args: %s\n", targs);            
                }

                if (debug) {
                    printf("executing\n");
                }
                
                if (tcmd[0] == 's' && targs[0] != '\0') {
                    if (targs[tpointer] == ' ') {
                        targs[tpointer - 1] = '\0';
                    }
                    printf("%s\n", targs);
                }

                tcmd[0] = '\0';
                targs[0] = '\0';
                tpointer = 0;

                if (debug) {
                    // not using the back slash to avoid errors in /0
                    printf("tcmd AND tpoint is now \\0 and tpointer is 0\n");
                }

                isEnd = false;
                
                return;
            }

            // if the command is right, this section shouldn't be executed i think idk lmao
            fuckinerror = true;
            printf("what is: %s\n", word);        
        }
    } else if (fuckinerror) {
        printf("yeah u fucked up :3\n");
        printf("you see the error so yeah, figure it urself :P\n");
    }
}

void lexer(char cmd[]) {
    char word[500];
    int point = 0;

    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == ' ' || cmd[i] == '\n') {
            word[point] = '\0';
            classify(word, point);
            point = 0;
            //printf("%s\n", word);
        } else {
            word[point] = cmd[i];
            point++;
        }
    }

    word[point] = '\0';
    //printf("%s\n", word);
    classify(word, point);
    point = 0;
}