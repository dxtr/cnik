#ifndef _CLIENT_H
#define _CLIENT_H

struct Client 
{
	char[65] nickname;
	char[65] username;
	char[65] server;
	void *channels;

	short unsigned int port;
	void *socket;
};

struct Client *clientCreate(const char *nickname, const char *username, void *channels, const char *server, short unsigned int port);
void clientDestroy(struct Client *client);
void clientConnect(struct Client *client);
void clientDisconnect(struct Client *client, const char *message);
void clientPart(struct Client *client, const char *channel);
void clientJoin(struct Client *client, const char *channel, const char *password);

void clientSetNick(struct Client *client, const char *nickname);
void clientSetServer(struct Client *client, const char *server);
void clientSetUsername(struct Client *client, const char *username);
void clientSetPort(struct Client *client, short unsigned int port);

#endif
