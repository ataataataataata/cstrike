#ifndef CSTRIKE_REQUEST_H
#define CSTRIKE_REQUEST_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

struct addrinfo *resolveHost(const char *url, const char *port);

int connectToHost(const char *host, const char *port);

int sendRequest(int sock, const char* host, const char* path);

double doRequest(const char* host, const char* port, const char* path);

#endif //CSTRIKE_REQUEST_H
