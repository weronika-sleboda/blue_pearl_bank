#include "bank_frame.h"
#include "network_controller.h"
#include <string>
#include "frame_controller.h"

namespace blue_pearl_bank
{

	BankFrame::BankFrame() :

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
		wxSize { 440, 120 }

	},

		messagePanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 113 },
		wxSize { 434, 114 }

	},

		message
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 40, 130 },
		wxSize { 400, 90 }

	},

		transactionBorderPanel
	{

		this,
		wxID_ANY,
		wxPoint { 20, 250 },
		wxSize { 150, 60 }

	},

		transactionPanel
	{

		this,
		wxID_ANY,
		wxPoint { 23, 253 },
		wxSize { 144, 54 }

	},

		transactionInfo
	{

		this,
		wxID_ANY,
		"AMOUNT: ",
		wxPoint { 60, 270 },
		wxSize { 100, 30 }

	},

		transactionField
	{

		this,
		wxID_ANY,
		"",
		wxPoint { 180, 250 },
		wxSize { 280, 60 }

	},

		balanceButton
	{

		this,
		wxID_ANY,
		"BALANCE",
		wxPoint { 20, 320 },
		wxSize { 140, 40 }

	},

		depositButton
	{

		this,
		wxID_ANY,
		"DEPOSIT",
		wxPoint { 168, 320 },
		wxSize { 140, 40 }

	},

		withdrawButton
	{
		this,
		wxID_ANY,
		"WITHDRAW",
		wxPoint { 315, 320 },
		wxSize { 145, 40 }
	},

		exitButton
	{

		this,
		wxID_ANY,
		"EXIT",
		wxPoint { 20, 370 },
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

		userInfo { "" },
		firstTimeReceivedUserInfo { true }

		//*** Constructor Body

	{

		SetBackgroundColour(colour.darkSteel);
		setUpTitlePanel();
		setupMessagePanel();
		setupTransactionPanel();
		setupButtons();
		setupAuthorInfo();
		activateButtons();

	}

	void BankFrame::setUpTitlePanel()
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

	void BankFrame::setupMessagePanel()
	{

		wxFont font
		{

			12,
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

	void BankFrame::setupTransactionPanel()
	{

		wxFont font
		{

			12,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_BOLD

		};

		transactionBorderPanel.SetBackgroundColour(colour.galactic);
		transactionPanel.SetBackgroundColour(colour.midSteel);
		transactionInfo.SetBackgroundColour(colour.midSteel);
		transactionInfo.SetForegroundColour(colour.galactic);
		transactionInfo.SetFont(font);

		transactionField.SetBackgroundColour(colour.midSteel);
		transactionField.SetForegroundColour(colour.lightSteel);
		transactionField.SetFont(font);

	}

	void BankFrame::setupButtons()
	{

		wxFont font
		{

			18,
			wxFONTFAMILY_ROMAN,
			wxFONTSTYLE_ITALIC,
			wxFONTWEIGHT_LIGHT

		};

		balanceButton.SetBackgroundColour(colour.lightSteel);
		balanceButton.SetForegroundColour(colour.darkSteel);
		balanceButton.SetFont(font);

		depositButton.SetBackgroundColour(colour.lightSteel);
		depositButton.SetForegroundColour(colour.darkSteel);
		depositButton.SetFont(font);

		withdrawButton.SetBackgroundColour(colour.lightSteel);
		withdrawButton.SetForegroundColour(colour.darkSteel);
		withdrawButton.SetFont(font);

		exitButton.SetBackgroundColour(colour.lightSteel);
		exitButton.SetForegroundColour(colour.darkSteel);
		exitButton.SetFont(font);

	}

	void BankFrame::setupAuthorInfo()
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

	void BankFrame::activateButtons()
	{

		balanceButton.Bind
		(wxEVT_BUTTON, &BankFrame::onClickShowBalance, this);

		depositButton.Bind
		(wxEVT_BUTTON, &BankFrame::onClickDeposit, this);

		withdrawButton.Bind
		(wxEVT_BUTTON, &BankFrame::onClickWithdraw, this);

		exitButton.Bind
		(wxEVT_BUTTON, &BankFrame::onClickExit, this);

	}

	void BankFrame::onClickShowBalance(wxCommandEvent& event)
	{

		if (firstTimeReceivedUserInfo)
		{

			firstTimeReceivedUserInfo = false;

			NetworkController::network().acquireData();

			userInfo =

				NetworkController::network().getServerData();

		}

		message.SetLabel(userInfo);

		event.Skip();

	}

	void BankFrame::onClickDeposit(wxCommandEvent& event)
	{

		if (firstTimeReceivedUserInfo)
		{

			firstTimeReceivedUserInfo = false;

			NetworkController::network().acquireData();

			userInfo =

				NetworkController::network().getServerData();

		}

		event.Skip();

	}

	void BankFrame::onClickWithdraw(wxCommandEvent& event)
	{

		if (firstTimeReceivedUserInfo)
		{

			firstTimeReceivedUserInfo = false;

			NetworkController::network().acquireData();

			userInfo =

				NetworkController::network().getServerData();

		}

		event.Skip();

	}

	void BankFrame::onClickExit(wxCommandEvent& event)
	{

		Hide();

		firstTimeReceivedUserInfo = true;

		FrameController::frameController().showLogInFrame();

		event.Skip();

	}

}