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

struct Sock sockCreate(void);
void sockDestroy(struct Sock *sock);

inline void sockSetRemotePort(struct Sock *s, uint8_t remoteport)
	{ if (s) s->remoteport = remoteport; }
inline void sockSetLocalPort(struct Sock *s, uint8_t localport)
	{ if (s) s->localport = localport; }
inline void sockSetConnected(struct Sock *s)
	{ if (s) s->isconnected = 1; } 
inline void sockSetDisconnected(sstruct Sock *s)
	{ if (s) s->isconnected = 0; }
inline void sockToggleConnected(struct Sock *s)
	{ if (s) s->isconnected = !(s->isconnected); }

#endif

