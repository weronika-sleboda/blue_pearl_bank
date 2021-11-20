#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "client.h"
#include <string>

namespace blue_pearl_bank
{

	class ClientManager : public Client
	{

	public:

		ClientManager();

	public:

		virtual const unsigned const short getPortNumber() const override;
		virtual const std::string const getIpAddress() const override;

	public:

		bool openSocket();
		bool connectSocket();
		bool sendData(const std::string& message);
		bool acquireData();
		const std::string const getServerData();

	private:

		boost::asio::ip::tcp::endpoint endpoint;
		std::string serverData;

	};

}

#endif