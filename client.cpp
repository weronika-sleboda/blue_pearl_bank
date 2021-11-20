#include "client.h"

namespace blue_pearl_bank
{

	Client::Client() :

		portNumber{ 3333 },
		ipAddress{ "127.0.0.1" },
		socket { ioService }

	{}

	const unsigned short const Client::getPortNumber() const
	{

		return portNumber;

	}

	const std::string const Client::getIpAddress() const
	{

		return ipAddress;

	}

}

