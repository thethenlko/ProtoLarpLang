#ifndef TSMTH_H
#define TSMTH_H
#include <stdbool.h>

extern bool fuckingerror;
extern char endsymbol[5];


enum typeofcmds {
    CMD_NOSHIT,
    CMD_SAY,
    CMD_WAIT
};

struct rncmd {
    enum typeofcmds type;
    char args[300];
    int iargs;
    int pointer;
    bool isend;
};

extern struct rncmd currentcmd;


#endif