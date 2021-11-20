#include "log_in_frame.h"
#include <string>
#include "frame_controller.h"
#include "network_controller.h"

namespace blue_pearl_bank
{

	LogInFrame::LogInFrame() :

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
		wxSize { 440, 80 }

	},

		messagePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 113 },
		wxSize { 434, 74 }

	},

		message
	{

		this,
		wxID_ANY,
		"Log in.",
		wxPoint { 40, 130 },
		wxSize { 400, 50 }

	},

		emailBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 220 },
		wxSize { 150, 40 }

	},

		emailPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 223 },
		wxSize { 144, 34 }

	},

		emailInfo
	{

		this,
		wxID_ANY,
		"Email address:",
		wxPoint { 40, 230 },
		wxSize { 120, 25 }

	},
		emailField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 220 },
		wxSize { 280, 40 }

	},

		passwordBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 270 },
		wxSize { 150, 40 }

	},

		passwordPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 273 },
		wxSize { 144, 34 }

	},

		passwordInfo
	{

		this,
		wxID_ANY,
		"Password:",
		wxPoint { 40, 280 },
		wxSize { 120, 20 }

	},
		
		passwordField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 270 },
		wxSize { 280, 40 }

	},

		createAccountButton
	{

		this,
		wxID_ANY,
		"CREATE ACCOUNT",
		wxPoint { 20, 380 },
		wxSize { 220, 40 }

	},

		logInButton
	{
		this,
		wxID_ANY,
		"LOG IN",
		wxPoint { 250, 380 },
		wxSize { 210, 40 }
	},

		authorInfo
	{

		this,
		wxID_ANY,
		"2021 Weronika Sleboda",
		wxPoint { 25, 430 },
		wxSize { 440, 20 }

	}

	//*** Constructor Body

	{

		SetBackgroundColour(colour.darkSteel);
		setUpTitlePanel();
		setupMessagePanel();
		setupEmailPanel();
		setupPasswordPanel();
		setupButtons();
		setupAuthorInfo();
		activateButtons();

	}

	void LogInFrame::setUpTitlePanel()
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

	void LogInFrame::setupMessagePanel()
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

	void LogInFrame::setupEmailPanel()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		emailBorderPanel.SetBackgroundColour(colour.galactic);
		emailPanel.SetBackgroundColour(colour.midSteel);
		emailInfo.SetBackgroundColour(colour.midSteel);
		emailInfo.SetForegroundColour(colour.galactic);
		emailInfo.SetFont(font);

		emailField.SetBackgroundColour(colour.midSteel);
		emailField.SetForegroundColour(colour.lightSteel);
		emailField.SetFont(font);

	}

	void LogInFrame::setupPasswordPanel()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		passwordBorderPanel.SetBackgroundColour(colour.galactic);
		passwordPanel.SetBackgroundColour(colour.midSteel);
		passwordInfo.SetBackgroundColour(colour.midSteel);
		passwordInfo.SetForegroundColour(colour.galactic);
		passwordInfo.SetFont(font);

		passwordField.SetBackgroundColour(colour.midSteel);
		passwordField.SetForegroundColour(colour.lightSteel);
		passwordField.SetFont(font);

	}

	void LogInFrame::setupButtons()
	{

		wxFont font
		{

			18,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		createAccountButton.SetBackgroundColour(colour.lightSteel);
		createAccountButton.SetForegroundColour(colour.darkSteel);
		createAccountButton.SetFont(font);

		logInButton.SetBackgroundColour(colour.lightSteel);
		logInButton.SetForegroundColour(colour.darkSteel);
		logInButton.SetFont(font);

	}

	void LogInFrame::setupAuthorInfo()
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

	void LogInFrame::activateButtons()
	{

		createAccountButton.Bind
		(wxEVT_BUTTON, &LogInFrame::onClickCreateAccount, this);

		logInButton.Bind
		(wxEVT_BUTTON, &LogInFrame::onClickLogIn, this);

	}

	void LogInFrame::onClickCreateAccount(wxCommandEvent& event)
	{

		Hide();

		FrameController::frameController().showAccountCreatorFrame();

		event.Skip();

	}

	void LogInFrame::onClickLogIn(wxCommandEvent& event)
	{
		//*** 1. Tell the server about communication type:

		NetworkController::network().sendData("LOG_IN");

		wxString login =

			emailField.GetValue() + '\n' + passwordField.GetValue();

		//*** 2. Send login to the server:

		NetworkController::network().sendData(login.ToStdString());

		//*** 3. Ask server if login is correct:

		NetworkController::network().acquireData();

		std::string serverResponse =

			NetworkController::network().getServerData();

		serverResponse.pop_back();

		emailField.Clear();
		passwordField.Clear();

		if (serverResponse == "LOG_IN_ACCEPTED")
		{

			Hide();
			FrameController::frameController().showBankFrame();

		}

		else
		{

			message.SetLabel
			("Your email address or password is incorrect.");

		}

		
		event.Skip();

	}

}