#pragma once

#include "Parser.h"
#include "ThreadSafeQueue.h"

class ModbusOperation;

class TWParser : public Parser<ClientState>
{
	bool hasCompleteMessage(ClientState * client);
	std::string extractCompleteMessageFromBuffer(ClientState * client);

public:
	TWParser();
	~TWParser();

	void parse(ClientState * client, std::vector<unsigned char> & receivedPacket);
	void parse(SOCKET sock, unsigned char * buf, int length);
};

