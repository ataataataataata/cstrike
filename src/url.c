#include "url.h"

// http://localhost:8080/api/users
URL parseURL(const char *url) {

    URL result;

    //  get host: localhost
    char* firstPtr = strstr(url, "://");
    firstPtr+=3;
    char* lastPtr = strstr(firstPtr, ":");
    strncpy(result.host,firstPtr, lastPtr-firstPtr);
    result.host[lastPtr - firstPtr] = '\0';

    // get port: 8080
    char* slash = strstr(lastPtr, "/");
    lastPtr+=1;
    strncpy(result.port,lastPtr, slash-lastPtr);
    result.port[slash-lastPtr] = '\0';

    //get path:
    strcpy(result.path,slash);

    return result;
}