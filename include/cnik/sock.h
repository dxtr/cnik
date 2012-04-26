#ifndef _SOCK_H
#define _SOCK_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>

enum EAFReq {
	RAF_ANY = PF_UNSPEC,
	RAF_INET6 = PF_INET6,
	RAF_INET = AF_INET
};

struct SockAddr {
	struct sockaddr_in saddr;
	struct sockaddr_in6 saddr6;

	enum EAFReq afreq;
};

struct Sock {
	struct SockAddr address;
	struct SockAddr bindaddress;

	char *buffer;

	uint8_t remoteport;
	uint8_t localport;
	uint8_t isconnected;

	int readsock;
	int writesock;
};

struct Sock sockCreate(void);
void sockDestroy(struct Sock *sock);

#endif

