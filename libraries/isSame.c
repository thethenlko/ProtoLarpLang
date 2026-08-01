#include "isSame.h"
#include <stdio.h>

int issame(char yes[], char bye[]) {
    int same = 1;

    for (int i = 0; yes[i] != '\0' || bye[i] != '\0'; i++) {
        if (yes[i] != bye[i]) {
            same = 0;
            break;
        }
    }

    return same;
}