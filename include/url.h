#ifndef CSTRIKE_URL_H
#define CSTRIKE_URL_H

#include <string.h>

typedef struct URL {
    char host[256];
    char port[8];
    char path[256];
} URL;

URL parseURL(const char *url);

#endif //CSTRIKE_URL_H
