#ifndef TSMTH_H
#define TSMTH_H
#include <stdbool.h>

extern bool fuckingerror;
extern char endsymbol[];


enum typeofcmds {
    CMD_NOSHIT,
    CMD_SAY,
    CMD_WAIT
};

struct rncmd {
    enum typeofcmds type;
    char args[600];
    int iargs;
    int pointer;
    bool isend;
};

extern struct rncmd currentcmd;


#endif