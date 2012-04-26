#ifndef _SOCK_H
#define _SOCK_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdint.h>

enum EAFReq {
	RAF_ANY = PF_UNSPEC,
	RAF_INET6 = PF_INET6,
	RAF_INET = AF_INET
};

struct SockAddr {
	struct addrinfo *ai;

	enum EAFReq afreq;
};

struct Sock {
	struct SockAddr *address;
	struct SockAddr *bindaddress;

	char *buffer;

	uint8_t remoteport;
	uint8_t localport;
	uint8_t isconnected;

	int readsock;
	int writesock;
};

struct SockAddr *sockAddrCreate(enum EAFReq afreq, const char *hostname, const char *service);
void sockAddrDestroy(struct SockAddr *sa);

struct Sock *sockCreate(struct SockAddr *address, struct SockAddr *bindaddress);
void sockDestroy(struct Sock *sock);

void sockSetRemotePort(struct Sock *s, uint8_t remoteport);
void sockSetLocalPort(struct Sock *s, uint8_t localport);
void sockSetConnected(struct Sock *s);
void sockSetDisconnected(struct Sock *s);
void sockToggleConnected(struct Sock *s);

#endif

