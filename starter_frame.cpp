#include "starter_frame.h"
#include <thread>
#include "frame_controller.h"
#include "network_controller.h"

namespace blue_pearl_bank
{

	StarterFrame::StarterFrame() :

		wxFrame
	{

		nullptr,
		wxID_ANY,
		"Blue Pearl Bank",
		wxPoint { 5, 10 },
		wxSize { 500, 500 }

	},

		titleBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 20 },
		wxSize { 440, 60 }

	},

		titlePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 23 },
		wxSize { 434, 54 }

	},

		title
	{

		this,
		wxID_ANY,
		"BLUE PEARL BANK",
		wxPoint { 100, 30 },
		wxSize { 200, 40 }

	},

		messageBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 110 },
		wxSize { 440, 240 }

	},

		messagePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 113 },
		wxSize { 434, 234 }

	},

		message
	{

		this,
		wxID_ANY,
		"Connect to server in order to use the application.",
		wxPoint { 40, 130 },
		wxSize { 400, 200 }

	},

		connectButton
	{

		this,
		wxID_ANY,
		"CONNECT",
		wxPoint { 20, 380 },
		wxSize { 440, 40 }

	},

		authorInfo
	{

		this,
		wxID_ANY,
		"2021 Weronika Sleboda",
		wxPoint { 25, 430 },
		wxSize { 440, 20 }

	},

		buttonClicked{ false }


		//*** Constructor Body

	{

		SetBackgroundColour(colour.darkSteel);
		setUpTitlePanel();
		setupMessagePanel();
		setupConnectButton();
		setupAuthorInfo();
		activateConnectButton();

	}

	void StarterFrame::setUpTitlePanel()
	{

		wxFont font
		{

			25,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		titleBorderPanel.SetBackgroundColour(colour.steel);
		titlePanel.SetBackgroundColour(colour.galactic);
		title.SetBackgroundColour(colour.galactic);
		title.SetForegroundColour(colour.lightSteel);
		title.SetFont(font);

	}

	void StarterFrame::setupMessagePanel()
	{

		wxFont font
		{

			14,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_LIGHT

		};

		messageBorderPanel.SetBackgroundColour(colour.lightSteel);
		messagePanel.SetBackgroundColour(colour.steel);
		message.SetBackgroundColour(colour.steel);
		message.SetForegroundColour(colour.lightSteel);
		message.SetFont(font);

	}

	void StarterFrame::setupConnectButton()
	{

		wxFont font
		{

			18,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		connectButton.SetBackgroundColour(colour.lightSteel);
		connectButton.SetForegroundColour(colour.darkSteel);
		connectButton.SetFont(font);

	}

	void StarterFrame::setupAuthorInfo()
	{

		wxFont font
		{

			10,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		authorInfo.SetForegroundColour(colour.lightSteel);
		authorInfo.SetFont(font);

	}

	void StarterFrame::activateConnectButton()
	{

		connectButton.Bind
		(wxEVT_BUTTON, &StarterFrame::onClickConnectToServer, this);

	}

	void StarterFrame::onClickConnectToServer(wxCommandEvent& event)
	{

		if (!buttonClicked)
		{

	
			showWaitForConnectionMessage();

			if (NetworkController::network().runClient())
			{

				buttonClicked = true;

				Hide();

				FrameController::frameController().showLogInFrame();
			
				event.Skip();
				
			}

			else
			{

				message.SetLabel
				("The client couldn't connect to the server.");

				event.Skip();

			}

			connectButton.Enable();

		}

	}

	void StarterFrame::showWaitForConnectionMessage()
	{

		std::string info = "Please wait, connecting to server";

		connectButton.Disable();

		for (int counter = 1; counter <= 8; counter++)
		{

			if (info == "Please wait, connecting to server....")
			{

				info = "Please wait, connecting to server";

			}

			message.SetLabel(info);
			info += ".";
			std::this_thread::sleep_for(std::chrono::milliseconds(600));

		}

	}

}
