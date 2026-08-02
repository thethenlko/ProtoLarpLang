#ifndef TSMTH_H
#define TSMTH_H
#include <stdbool.h>

#define max_vars 100

extern bool fuckingerror;
extern char endsymbol[];

struct var {
    char name[100];
    char value[100];
};


enum typeofcmds {
    CMD_NOSHIT,
    CMD_SAY,
    CMD_WAIT,
    CMD_SET
};

struct rncmd {
    enum typeofcmds type;
    char args[600];
    char args2[600];
    int iargs;
    int pointer;
    int pointer2;
    int argcount;
    bool isend;
};

extern struct rncmd currentcmd;
extern struct var vars[max_vars];
extern int somanyvars;

#endif