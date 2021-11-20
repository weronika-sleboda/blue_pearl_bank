#include "network_controller.h"
#include "client_manager.h"

namespace blue_pearl_bank
{

	NetworkController::NetworkController() :

		clientManager { nullptr }

	{}

	NetworkController::~NetworkController()
	{

		delete clientManager;

	}

	NetworkController& NetworkController::network()
	{

		static NetworkController controller;
		return controller;

	}

	bool NetworkController::runClient()
	{

		clientManager = new ClientManager { };

		if (clientManager->openSocket() && clientManager->connectSocket())
		{

			return true;

		}

		else 
		{

			return false;

		}

	}

	void NetworkController::sendData(const std::string& message)
	{

		clientManager->sendData(message);

	}

	void NetworkController::acquireData()
	{

		clientManager->acquireData();

	}

	const std::string const NetworkController::getServerData()
	{

		return clientManager->getServerData();

	}

}