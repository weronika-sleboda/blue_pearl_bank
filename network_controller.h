#ifndef NETWORK_CONTROLLER_H
#define NETWORK_CONTROLLER_H

#include <string>

namespace blue_pearl_bank
{

	class ClientManager;

	class NetworkController
	{

	public:

		~NetworkController();

	public:

		static NetworkController& network();
		bool runClient();
		void sendData(const std::string& message);
		void acquireData();
		const std::string const getServerData();

	private:

		NetworkController();
		NetworkController(NetworkController&) = delete;
		NetworkController(NetworkController&&) = delete;
		NetworkController& operator=(NetworkController&) = delete;
		NetworkController& operator=(NetworkController&&) = delete;

	private:

		ClientManager* clientManager;

	};

}

#endif