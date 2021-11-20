#ifndef ACCOUNT_CREATOR_FRAME_H
#define ACCOUNT_CREATOR_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"

namespace blue_pearl_bank
{

	class AccountCreatorFrame : public wxFrame
	{

	public:

		AccountCreatorFrame();

	private:

		void setUpTitlePanel();
		void setupMessagePanel();
		void setupFirstNamePanel();
		void setupLastNamePanel();
		void setupEmailPanel();
		void setupPasswordPanel();
		void setupButtons();
		void setupAuthorInfo();
		void activateButtons();

		//*** Button Action

		void onClickCreateAccount(wxCommandEvent& event);
		void onClickExit(wxCommandEvent& event);

	private:

		ColourPalette colour;

	private:

		//*** Title Panel

		wxPanel titleBorderPanel;
		wxPanel titlePanel;
		wxStaticText title;

		//*** MessagePanel

		wxPanel messageBorderPanel;
		wxPanel messagePanel;
		wxStaticText message;

		//*** First Name Panel

		wxPanel firstNameBorderPanel;
		wxPanel firstNamePanel;
		wxStaticText firstNameInfo;
		wxTextCtrl firstNameField;

		//*** Last Name Panel

		wxPanel lastNameBorderPanel;
		wxPanel lastNamePanel;
		wxStaticText lastNameInfo;
		wxTextCtrl lastNameField;

		//*** Email Address Panel

		wxPanel emailBorderPanel;
		wxPanel emailPanel;
		wxStaticText emailInfo;
		wxTextCtrl emailField;

		//*** Password Panel

		wxPanel passwordBorderPanel;
		wxPanel passwordPanel;
		wxStaticText passwordInfo;
		wxTextCtrl passwordField;

		//*** Button

		wxButton exitButton;
		wxButton createAccountButton;

		//*** Author Info

		wxStaticText authorInfo;

	};

}

#endif