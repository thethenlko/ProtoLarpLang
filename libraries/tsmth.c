#include "tsmth.h"

bool fuckingerror = false;
char endsymbol[5] = "OwO";

struct rncmd currentcmd = {
    .type = CMD_NOSHIT,
    .args = "",
    .iargs = 0,
    .pointer = 0,
    .isend = false
};