#ifndef CSTRIKE_REQUEST_H
#define CSTRIKE_REQUEST_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

struct addrinfo *resolveHost(const char *url, const char *port);

#endif //CSTRIKE_REQUEST_H
