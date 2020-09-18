#include "TWParser.h"
#include <iostream>

#include "TcpServer.h"
#include "StringUtils.h"

TWParser::TWParser()
{
}


TWParser::~TWParser()
{
}

bool TWParser::hasCompleteMessage(ClientState * client)
{
	bool result = false;
	std::deque<unsigned char> & buffer = client->getBuffer();

	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == '\n')
		{
			result = true;
			break;
		}
	}

	return result;
}

std::string TWParser::extractCompleteMessageFromBuffer(ClientState * client)
{
	std::string result;
	int i = 0;
	std::deque<unsigned char> & buffer = client->getBuffer();
	
	while (buffer.front() != '\n')
	{
		result += buffer.front();
		buffer.pop_front();
	}

	buffer.pop_front();	// To remove the '\n' from the buffer.

	return result;
}

void TWParser::parse(ClientState * client, std::vector<unsigned char> & receivedPacket)
{
	std::deque<unsigned char> & buffer = client->getBuffer();

	for (int i = 0; i < receivedPacket.size(); i++)
	{
		unsigned char c = receivedPacket[i];
		buffer.push_back(c);
	}

	// Implémentation du protocole :
	if (hasCompleteMessage(client))
	{
		std::string toParse = extractCompleteMessageFromBuffer(client);

		if (StringUtils::startsWith(toParse, "HG"))
		{
			TcpServer<TWParser, ClientState>::Send(client, (char*)"Hello\n", 6);
		}

		/*
		long sentenceLength = buffer.size();
		unsigned char * sentence = new unsigned char[sentenceLength];

		for (int i = 0; i < sentenceLength; i++)
		{
			sentence[i] = buffer[i];
		}

		TcpServer<TWParser, ClientState>::Send(client, (char*)sentence, sentenceLength);
		delete sentence;
		buffer.clear();
		*/
	}
}

void TWParser::parse(SOCKET sock, unsigned char * buf, int length)
{
	Parser<ClientState>::parse(sock, buf, length);
}
