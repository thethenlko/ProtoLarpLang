#include <stdio.h>
#include <stdlib.h>
#include "isSame.h"
#include "parser.h"
#include "tsmth.h"
#include "executor.h"

// i fucking hate this :(

// if you reading this, fuck this shit bro :(
// atleast i made a programming language lmao
// easier than python btw

void parser(char word[], int point) {
    bool debug = false;

    if (debug) {
        printf("word is %s\n", word);
    }


    //printf("arg %s", currentcmd.args);

    if (point > 0 && !fuckingerror) {
        // couldve used a switch (case) statement but meh
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
        } else if (issame(word, "set") && currentcmd.type == CMD_NOSHIT) {
            currentcmd.type = CMD_SET;
            if (debug) {
                printf("command: set\n");
            }
            return;
        } else {
            if (issame(word, endsymbol)) {
                currentcmd.isend = true;

                if (debug) {
                    printf("end\n");
                }

            }
            if (!currentcmd.isend) {
                if (currentcmd.type == CMD_SAY && currentcmd.pointer < 599) {
                    if (word[0] == '~') {
                        for (int var = 0; var < somanyvars; var++) {
                            if (issame(vars[var].name, word + 1)) {
                                if (debug) {
                                    printf("variable %s\n", vars[var].name);
                                    printf("value %s\n", vars[var].value);
                                }
                                for (int hi = 0; vars[var].value[hi] != '\0' && hi < 599; hi++) {
                                    currentcmd.args[currentcmd.pointer] = vars[var].value[hi];
                                    currentcmd.pointer++;
                                }
                                return;
                            }
                        }
                        printf("variable not found %s\n", word + 1);
                        fuckingerror = true;
                        return;
                    }
                
                    for (int i = 0; word[i] != '\0' && i < 599; i++) {
                        
                        currentcmd.args[currentcmd.pointer] = word[i];
                        currentcmd.pointer++;
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
                if (currentcmd.type == CMD_SET) {
                    if (currentcmd.argcount == 0) {
                        for (int i = 0; word[i] != '\0' && i < 599; i++) {
                            currentcmd.args[currentcmd.pointer] = word[i];
                            currentcmd.pointer++;
                        }
                        currentcmd.args[currentcmd.pointer] = '\0';
                        currentcmd.argcount++;
                        if (debug) {
                            printf("name: %s\n", currentcmd.args);
                        }
                        return;
                    } else if (currentcmd.argcount >= 1) {
                        for (int i = 0; word[i] != '\0' && i < 599; i++) {
                            currentcmd.args2[currentcmd.pointer2] = word[i];
                            currentcmd.pointer2++;
                        }
                        currentcmd.args2[currentcmd.pointer2] = ' ';
                        currentcmd.pointer2++;
                        currentcmd.args2[currentcmd.pointer2] = '\0';
                        if (debug) {
                            printf("value: %s\n", currentcmd.args2);
                        }
                        return;
                    } else if (currentcmd.argcount == 1 && currentcmd.pointer2 == 0) {
                        currentcmd.args2[0] = '\0';
                        if (debug) {
                            printf("value: %s\n", currentcmd.args2);
                        }
                        return;
                    } else {
                        printf("what is: %s\n", word);
                        fuckingerror = true;
                        return; 
                    }
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
                    if (currentcmd.type == CMD_SET) {
                        printf("current: set\n");
                    }
                    printf("args: %s\n", currentcmd.args);            
                }

                if (debug) {
                    printf("executing\n");
                }

                execute_this(currentcmd);

                currentcmd.type = CMD_NOSHIT;
                currentcmd.args[0] = '\0';
                currentcmd.args2[0] = '\0';
                currentcmd.iargs = 0;
                currentcmd.pointer = 0;
                currentcmd.isend = false;
                currentcmd.pointer2 = 0;
                currentcmd.argcount = 0;

                if (debug) {
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