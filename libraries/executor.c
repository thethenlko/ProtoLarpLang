#include "executor.h"
#include <stdio.h>
#include "isSame.h"
#include "time.h"
#include "tsmth.h"
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
        case CMD_SET:
            if (somanyvars < max_vars) {
                for (int i = 0; i < somanyvars; i++) {
                    if (issame(vars[i].name, yescmd.args)) {
                        for (int hi = 0; hi < 300; hi++) {
                            vars[i].value[hi] = yescmd.args2[hi];
                        }
                        return;
                    }
                }
                for (int hi = 0; hi < max_vars; hi++) {
                    vars[somanyvars].name[hi] = yescmd.args[hi];
                    vars[somanyvars].value[hi] = yescmd.args2[hi];
                }
                somanyvars++;
            } else {
                printf("executor says that i have too much variables holy shit\n");
            }
            printf("set %s to %s\n", yescmd.args, yescmd.args2);
            break;
        default:
            break;
    }
}