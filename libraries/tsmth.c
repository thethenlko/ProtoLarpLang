#include "tsmth.h"

bool fuckingerror = false;
char endsymbol[5] = "OwO";

struct rncmd currentcmd = {
    .type = CMD_NOSHIT,
    .args = "",
    .args2 = "",
    .argcount = 0,
    .iargs = 0,
    .pointer = 0,
    .pointer2 = 0,
    .isend = false
};

struct var vars[max_vars];
int somanyvars = 0;