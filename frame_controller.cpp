#include "frame_controller.h"
#include "starter_frame.h"
#include "log_in_frame.h"
#include "account_creator_frame.h"
#include "bank_frame.h"
#include "network_controller.h"

namespace blue_pearl_bank
{

	FrameController::FrameController() :

		starterFrame { new StarterFrame { } },
		logInFrame { new LogInFrame { } },
		accountCreatorFrame { new AccountCreatorFrame { } },
		bankFrame { new BankFrame { } }

	{}

	FrameController::~FrameController()
	{

		delete starterFrame;
		delete logInFrame;
		delete accountCreatorFrame;

	}

	FrameController& FrameController::frameController()
	{

		static FrameController controller;
		return controller;

	}

	void FrameController::showStarterFrame()
	{

		starterFrame->Show();

	}

	void FrameController::showLogInFrame() 
	{

		logInFrame->Show();

	}

	void FrameController::showAccountCreatorFrame()
	{

		accountCreatorFrame->Show();

	}

	void FrameController::showBankFrame() 
	{

		bankFrame->Show();
		
	}


}
