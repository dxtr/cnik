#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#include <cnik/sock.h>
#include <cnik/dns.h>


int main(int argc, char **argv)
{
	struct addrinfo *ai = resolveHost(AF_UNSPEC, "www.google.com", NULL);
	struct addrinfo *i;
	printf("cnik starting\n");

	if (ai) {
		printf("Resolved host!\n");
		for (i = ai; i != NULL; i = i->ai_next) {
			void *addr;
			char *ipver;
			char ipstr[INET6_ADDRSTRLEN];

			if (i->ai_family == AF_INET) {
				struct sockaddr_in *v4 = (struct sockaddr_in*)i->ai_addr;
				addr = &(v4->sin_addr);
				ipver = "IPv4";
			} else if (i->ai_family == AF_INET) {
				struct sockaddr_in6 *v6 = (struct sockaddr_in6*)i->ai_addr;
				addr = &(v6->sin6_addr);
				ipver = "IPv6";
			} else {
				printf("Uknown address family");
				continue;
			}

			inet_ntop(i->ai_family, addr, ipstr, sizeof(ipstr));
			printf("%s: %s\n", ipver, ipstr);
		}
	}
	return 1;
}
