#pragma once
#include <Windows.h>

class ParserEventListener
{
public:
	virtual void onClientKicked(SOCKET sock) = 0;
};

