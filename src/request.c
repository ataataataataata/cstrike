#include "../include/request.h"

struct addrinfo *resolveHost(const char *url, const char *port) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);

    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    getaddrinfo(url, port, &hints, &res);

    return res;
}

int connectToHost(const char *host, const char *port) {
    struct addrinfo *servinfo = resolveHost(host, port);

    int sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    connect(sockfd,servinfo->ai_addr, servinfo->ai_addrlen);
    freeaddrinfo(servinfo);

    return sockfd;
}

int sendRequest(int sockfd, const char *host, const char *path) {
    char request[1024];
    snprintf(request, sizeof(request),
    "GET %s HTTP/1.1\r\n"
    "Host: %s\r\n"
    "Connection: close\r\n"
    "\r\n",
    path, host);

    return send(sockfd, request, strlen(request), 0);
}