#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdint.h>

#include <cnik/sock.h>
#include <cnik/dns.h>

struct SockAddr *sockAddrCreate(enum EAFReq afreq, const char *hostname, const char *service)
{
	struct SockAddr *sa = NULL;
	
	if (!hostname) return NULL;

	sa = malloc(sizeof(sockAddrCreate));
	if (sa) {
		memset(sa, 0, sizeof(struct SockAddr));
		sa->ai = resolveHost(afreq, hostname, service);
		sa->afreq = afreq;
	}
	return sa;
}

void sockAddrDestroy(struct SockAddr *sa)
{
	if (sa) {
		if (sa->ai) freeaddrinfo(sa->ai);
		free(sa);
	}
}

struct Sock *sockCreate(struct SockAddr *address, struct SockAddr *bindaddress)
{
	struct Sock *s = malloc(sizeof(struct Sock));
	if (s) {
		memset(s, 0, sizeof(struct Sock));
		s->address = address;
		s->bindaddress = bindaddress;
	}
	return s;
}

