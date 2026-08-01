#include "executor.h"
#include <stdio.h>
#include "time.h"
#include <unistd.h>

void execute_this(struct rncmd yescmd) {
    switch (yescmd.type) {
        case CMD_SAY:
            printf("%s\n", yescmd.args);
            break;
        case CMD_WAIT:
            if (yescmd.iargs > 0) {
                sleep(yescmd.iargs);
            }
            break;
        default:
            break;
    }
}