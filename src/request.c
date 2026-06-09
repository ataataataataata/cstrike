#include "../request.h"

struct addrinfo *resolveHost(const char *url, const char *port) {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);

    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    getaddrinfo(url, port, &hints, &res);

    return res;
}
