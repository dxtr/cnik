#include "client.h"

struct Client *clientcreate(const char *nickname, const  char *username, void *channels, const char *server, short unsigned  int port)
{
	struct Client *c = malloc(sizeof(struct Client));
	
	memset(c,0,sizeof(sturct Client));

	if(c)
	{
		strncpy(c->nickname, nickname, 64);
		strncpy(c->username, username, 64);
		strncpy(c->server, server, 64);
		c->port = port;
	}
}

void clientDestroy(struct Client *client)
{
}

void clientConnect(struct Client *client)
{
}

void clientDisconnect(struct Client *client, const char *message)
{
}

void clientPart(struct Client *client, const char *channel)
{
}

void clientJoin(struct client *client, const char *channel, const char *password)
{
}

void clientSetNick(struct Client *client, const char *nickname)
{
}

void clientSetServer(struct Client *client, const char *server)
{
}

void clientSetUsername(struct Client *client, const char *username)
{
}

void clientSetPort(struct Client *client, short unsigned int port)
{
}
