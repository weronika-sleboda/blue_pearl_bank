#include "account_creator_frame.h"
#include "network_controller.h"
#include "frame_controller.h"

namespace blue_pearl_bank
{

	AccountCreatorFrame::AccountCreatorFrame() :

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
		wxPoint { 20, 100 },
		wxSize { 440, 70 }

	},

		messagePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 103 },
		wxSize { 434, 64 }

	},

		message
	{

		this,
		wxID_ANY,
		"Log in.",
		wxPoint { 30, 106 },
		wxSize { 400, 50 }

	},

		firstNameBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 180 },
		wxSize { 150, 40 }

	},

		firstNamePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 183 },
		wxSize { 144, 34 }

	},

		firstNameInfo
	{

		this,
		wxID_ANY,
		"First Name:",
		wxPoint { 40, 190 },
		wxSize { 120, 20 }

	},

		firstNameField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 180 },
		wxSize { 280, 40 }

	},

		lastNameBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 230 },
		wxSize { 150, 40 }

	},

		lastNamePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 233 },
		wxSize { 144, 34 }

	},

		lastNameInfo
	{

		this,
		wxID_ANY,
		"Last Name:",
		wxPoint { 40, 240 },
		wxSize { 120, 20 }

	},

		lastNameField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 230 },
		wxSize { 280, 40 }

	},

		emailBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 280 },
		wxSize { 150, 40 }

	},

		emailPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 283 },
		wxSize { 144, 34 }

	},

		emailInfo
	{

		this,
		wxID_ANY,
		"Email address:",
		wxPoint { 40, 290 },
		wxSize { 120, 25 }

	},
		emailField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 280 },
		wxSize { 280, 40 }

	},

		passwordBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 330 },
		wxSize { 150, 40 }

	},

		passwordPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 333 },
		wxSize { 144, 34 }

	},

		passwordInfo
	{

		this,
		wxID_ANY,
		"Password:",
		wxPoint { 40, 339 },
		wxSize { 120, 20 }

	},

		passwordField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 330 },
		wxSize { 280, 40 }

	},

		exitButton
	{

		this,
		wxID_ANY,
		"EXIT",
		wxPoint { 20, 380 },
		wxSize { 220, 40 }

	},

		createAccountButton
	{
		this,
		wxID_ANY,
		"CREATE",
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
		setupFirstNamePanel();
		setupLastNamePanel();
		setupEmailPanel();
		setupPasswordPanel();
		setupButtons();
		setupAuthorInfo();
		activateButtons();

	}

	void AccountCreatorFrame::setUpTitlePanel()
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

	void AccountCreatorFrame::setupMessagePanel()
	{

		wxFont font
		{

			10,
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

	void AccountCreatorFrame::setupFirstNamePanel()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		firstNameBorderPanel.SetBackgroundColour(colour.galactic);
		firstNamePanel.SetBackgroundColour(colour.midSteel);
		firstNameInfo.SetBackgroundColour(colour.midSteel);
		firstNameInfo.SetForegroundColour(colour.galactic);
		firstNameInfo.SetFont(font);

		firstNameField.SetBackgroundColour(colour.midSteel);
		firstNameField.SetForegroundColour(colour.lightSteel);
		firstNameField.SetFont(font);

	}

	void AccountCreatorFrame::setupLastNamePanel()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		lastNameBorderPanel.SetBackgroundColour(colour.galactic);
		lastNamePanel.SetBackgroundColour(colour.midSteel);
		lastNameInfo.SetBackgroundColour(colour.midSteel);
		lastNameInfo.SetForegroundColour(colour.galactic);
		lastNameInfo.SetFont(font);

		lastNameField.SetBackgroundColour(colour.midSteel);
		lastNameField.SetForegroundColour(colour.lightSteel);
		lastNameField.SetFont(font);

	}

	void AccountCreatorFrame::setupEmailPanel()
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

	void AccountCreatorFrame::setupPasswordPanel()
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

	void AccountCreatorFrame::setupButtons()
	{

		wxFont font
		{

			18,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		exitButton.SetBackgroundColour(colour.lightSteel);
		exitButton.SetForegroundColour(colour.darkSteel);
		exitButton.SetFont(font);

		createAccountButton.SetBackgroundColour(colour.lightSteel);
		createAccountButton.SetForegroundColour(colour.darkSteel);
		createAccountButton.SetFont(font);

	}

	void AccountCreatorFrame::setupAuthorInfo()
	{

		wxFont font
		{

			11,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		authorInfo.SetForegroundColour(colour.lightSteel);
		authorInfo.SetFont(font);

	}

	void AccountCreatorFrame::activateButtons()
	{

		exitButton.Bind
		(wxEVT_BUTTON, &AccountCreatorFrame::onClickExit, this);

		createAccountButton.Bind
		(wxEVT_BUTTON, &AccountCreatorFrame::onClickCreateAccount, this);

	}

	void AccountCreatorFrame::onClickExit(wxCommandEvent& event)
	{

		Hide();

		FrameController::frameController().showLogInFrame();

		event.Skip();

	}

	void AccountCreatorFrame::onClickCreateAccount(wxCommandEvent& event)
	{

		NetworkController::network().sendData("CREATE_ACCOUNT");

		message.SetLabel("");
		message.SetForegroundColour(colour.lightSteel);

		wxString accountData =

			firstNameField.GetValue() + '?' +
			lastNameField.GetValue() + '?' +
			emailField.GetValue() + '?' +
			passwordField.GetValue();

		//*** [Explained]
		//*** '?' symbol will be used later in order to
		//*** split the data back into individual fields

		firstNameField.Clear();
		lastNameField.Clear();
		emailField.Clear();
		passwordField.Clear();

		//*** 1. Proposed user account:

		NetworkController::network().sendData(accountData.ToStdString());

		//*** 2. Ask server if account has been accepted:

		NetworkController::network().acquireData();


		std::string serverResponse =

			NetworkController::network().getServerData();

		serverResponse.pop_back();

		if (serverResponse == "ACCOUNT_ACCEPTED")
		{

			Hide();
			FrameController::frameController().showLogInFrame();
			event.Skip();

		}

		else
		{

			message.SetForegroundColour(colour.red);
			message.SetLabel(serverResponse);
			event.Skip();

		}

	}

}