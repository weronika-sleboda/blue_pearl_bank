#ifndef BANK_FRAME_H
#define BANK_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"
#include <string>

namespace blue_pearl_bank
{

	class BankFrame : public wxFrame
	{

	public:

		BankFrame();

	private:

		void setUpTitlePanel();
		void setupMessagePanel();
		void setupTransactionPanel();
		void setupButtons();
		void setupAuthorInfo();
		void activateButtons();

		//*** Button Action

		void onClickShowBalance(wxCommandEvent& event);
		void onClickDeposit(wxCommandEvent& event);
		void onClickWithdraw(wxCommandEvent& event);
		void onClickExit(wxCommandEvent& event);

	private:

		ColourPalette colour;

		std::string userInfo;

		bool firstTimeReceivedUserInfo;

	private:

		//*** Title Panel

		wxPanel titleBorderPanel;
		wxPanel titlePanel;
		wxStaticText title;

		//*** MessagePanel

		wxPanel messageBorderPanel;
		wxPanel messagePanel;
		wxStaticText message;

		//*** Transaction Panel

		wxPanel transactionBorderPanel;
		wxPanel transactionPanel;
		wxStaticText transactionInfo;
		wxTextCtrl transactionField;

		//*** Button

		wxButton balanceButton;
		wxButton depositButton;
		wxButton withdrawButton;
		wxButton exitButton;

		//*** Author Info

		wxStaticText authorInfo;
	};

}

#endif