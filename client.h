#ifndef _CLIENT_H
#define _CLIENT_H

struct Client 
{
	char[64] nickname, username, void *channels, server;
	short unsigned int port;
	void *socket;

	client();

}
struct Client *clientCreate(char *nickname, char *username, void *channels, char *server, int port);


#endif
