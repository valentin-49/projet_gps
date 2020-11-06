
#include "TcpServer.h"
#include "ClientState.h"
#include "TWParser.h"
#include "ParserEventListener.h"
#include <conio.h>

int main(int argc, char** argv)
{
	TcpServer<TWParser, ClientState> * server = new TcpServer<TWParser, ClientState>(12345);

	_getch();
	delete server;
	return 0;
}