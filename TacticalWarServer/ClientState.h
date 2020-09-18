#pragma once

#include <WS2tcpip.h>
#include <deque>

class ClientState
{
	SOCKET sock;
	std::deque<unsigned char> buffer;

public:
	ClientState(SOCKET sock);
	virtual ~ClientState();

	inline SOCKET getSocket() {
		return sock;
	}

	inline std::deque<unsigned char> & getBuffer() {
		return buffer;
	}
};

