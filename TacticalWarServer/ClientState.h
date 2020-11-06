#pragma once

#include <WS2tcpip.h>
#include <deque>

class ClientState
{
	SOCKET sock;
	std::deque<unsigned char> buffer;

	std::string pseudo;

public:
	ClientState(SOCKET sock);
	virtual ~ClientState();

	inline SOCKET getSocket() {
		return sock;
	}

	inline std::deque<unsigned char> & getBuffer() {
		return buffer;
	}

	inline void setPseudo(std::string pseudo)
	{
		this->pseudo = pseudo;
	}

	inline std::string getPseudo()
	{
		return pseudo;
	}

	inline bool isSpectator()
	{
		return pseudo.length() == 0;
	}
};

