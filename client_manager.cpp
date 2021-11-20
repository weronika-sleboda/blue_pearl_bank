#include "client_manager.h"

using namespace boost;

namespace blue_pearl_bank
{

	ClientManager::ClientManager() :

		endpoint
	{ 
		
		asio::ip::address::from_string(getIpAddress()), 
		getPortNumber() 
	
	},

		serverData { "" }
	
	//*** Constructor Body

	{}

	const std::string const ClientManager::getIpAddress() const
	{

		return Client::getIpAddress();

	}

	const unsigned const short ClientManager::getPortNumber() const
	{

		return Client::getPortNumber();

	}

	bool ClientManager::openSocket()
	{

		try
		{

			socket.open(endpoint.protocol());

			return true;

		}

		catch (system::system_error error)
		{

			return false;

		}

	}

	bool ClientManager::connectSocket()
	{

		try
		{

			socket.connect(endpoint);

			return true;

		}

		catch (system::system_error error)
		{

			return false;

		}

	}

	bool ClientManager::sendData(const std::string& message)
	{

		try
		{

			asio::write(socket, asio::buffer(message + '\n'));

			return true;

		}

		catch (system::system_error error)
		{

			return false;

		}

	}

	bool ClientManager::acquireData()
	{

		try
		{

			asio::streambuf buffer;
			asio::read_until(socket, buffer, "\n");
			serverData = asio::buffer_cast<const char*>(buffer.data());

			return true;

		}

		catch (system::system_error error)
		{

			return false;

		}

	}

	const std::string const ClientManager::getServerData()
	{

		return serverData;

	}

}