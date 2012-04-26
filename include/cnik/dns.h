#ifndef _DNS_H
#define _DNS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <cnik/sock.h>

struct addrinfo* resolveHost(const char *hostname, const char *service);

#endif

