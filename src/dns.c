#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

#include <cnik/dns.h>

struct addrinfo* resolveHost(int ai_family, const char *hostname, const char *service)
{
	int status;
	struct addrinfo hints;
	struct addrinfo *ai;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = ai_family;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	status = getaddrinfo(hostname, service, &hints, &ai);
	if (status != 0)
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));

	return ai;
}

