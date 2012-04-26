#ifndef _CLIENT_H
#define _CLIENT_H

struct Client 
{
	char[64] nickname;
	char[64] username;
	char[64] server;
	void *channels;

	short unsigned int port;
	void *socket;

	client();

}
struct Client *clientCreate(char *nickname, char *username, void *channels, char *server, int port);
void clientDestroy(struct Client *client);
void clientConnect(struct Client *client);
void clientDisconnect(struct Client *client, const char *message);
void clientPart(struct Client *client, const char *channel);
void clientJoin(struct Client *client, const char *channel, const char *password);

void clientSetNick(struct Client *client, char *nickname);
void clientSetServer(struct Client *client, char *server);
void clientSetUsername(struct Client *client, char *username);
void clientSetPort(struct Client *client, int port);

#endif
