#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>
#include <string>

namespace blue_pearl_bank 
{

	class Client
	{

	public:

		virtual ~Client() = default;

	protected:

		Client();

	protected:

		boost::asio::io_service ioService;
		boost::asio::ip::tcp::socket socket;

	protected:

		virtual const unsigned short const getPortNumber() const;
		virtual const std::string const getIpAddress() const;

	private:

		const unsigned short const portNumber;
		const std::string const ipAddress;

	};

}

#endif