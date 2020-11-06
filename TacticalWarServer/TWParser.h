#pragma once

#include "Parser.h"
#include "ParserEventListener.h"
#include "ThreadSafeQueue.h"
#include <Player.h>
#include <map>

class ModbusOperation;

class TWParser : public Parser<ClientState>
{
	bool hasCompleteMessage(ClientState * client);
	std::string extractCompleteMessageFromBuffer(ClientState * client);
	std::vector<tw::Player*> players;
	std::map<std::string, tw::Player*> playersMap;
	std::map<tw::Player*, ClientState*> connectedPlayerMap;

public:
	TWParser();
	~TWParser();

	virtual void onClientConnected(ClientState * client);
	virtual void parse(ClientState * client, std::vector<unsigned char> & receivedPacket);
	virtual void parse(SOCKET sock, unsigned char * buf, int length);
	virtual void onClientDisconnected(SOCKET sock);
	virtual void onClientDisconnected(ClientState * client);

	void kick(ClientState * client);
};

