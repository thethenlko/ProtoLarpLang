#include <stdio.h>
#include <stdlib.h>
#include "isSame.h"
#include "parser.h"
#include "tsmth.h"
#include "executor.h"

// i fucking hate this :(

void parser(char word[], int point) {
    bool debug = false;

    if (debug) {
        printf("word is %s\n", word);
    }


    //printf("arg %s", currentcmd.args);

    if (point > 0 && !fuckingerror) {
        // couldve used a switch statement but meh
        if (issame(word, "say") && currentcmd.type == CMD_NOSHIT) {
            currentcmd.type = CMD_SAY;
            if (debug) {
               printf("command: say\n");    
            }
            return;
        } else if (issame(word, "wait") && currentcmd.type == CMD_NOSHIT) {
            currentcmd.type = CMD_WAIT;
            if (debug) {
                printf("command: wait\n");
            }
            return;
        } else {
            if (issame(word, endsymbol)) {
                currentcmd.isend = true;

                if (debug) {
                    printf("end\n");
                }

            }
            // i fucking hate this part but this shit is working???
            if (!currentcmd.isend) {
                if (currentcmd.type == CMD_SAY && currentcmd.pointer < 299) {
                    for (int i = 0; word[i] != '\0' && i < 299; i++) {
                        currentcmd.args[currentcmd.pointer] = word[i];
                        //printf("arg is %s\n", yescmd.args);
                        currentcmd.pointer++;
                        //printf("pointer: %d\n", tpointer);
                    }
                    currentcmd.args[currentcmd.pointer] = ' ';
                    currentcmd.pointer++;

                    currentcmd.args[currentcmd.pointer] = '\0';

                    if (debug) {
                        printf("args: %s\n", currentcmd.args);
                    }
                    return;
                }
                if (currentcmd.type == CMD_WAIT) {
                    currentcmd.iargs = atoi(word);
                    if (debug) {
                        printf("wait time: %d\n", currentcmd.iargs);
                    }
                    return;
                }
            }
            if (currentcmd.isend) {
                if (debug) {
                    printf("end function\n");
                    if (currentcmd.type  == CMD_SAY) {
                        printf("current: say\n");
                    }
                    if (currentcmd.type == CMD_WAIT) {
                        printf("current: wait\n");
                    }
                    printf("args: %s\n", currentcmd.args);            
                }

                if (debug) {
                    printf("executing\n");
                }

                execute_this(currentcmd);

                currentcmd.type = CMD_NOSHIT;
                currentcmd.args[0] = '\0';\
                currentcmd.iargs = 0;
                currentcmd.pointer = 0;
                currentcmd.isend = false;

                if (debug) {
                    // not using the back slash to avoid errors in /0
                    printf("reseting EVERYTHING\n");
                }

                currentcmd.isend = false;
                
                return;
            }

            // if the command is right, this section shouldn't be executed i think idk lmao
            fuckingerror = true;
            printf("what is: %s\n", word);        
        }
    } else if (fuckingerror) {
        printf("yeah u fucked up :3\n");
        printf("you see the error so yeah, figure it urself :P\n");
    }
}