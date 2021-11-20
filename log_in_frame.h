#ifndef LOG_IN_FRAME_H
#define LOG_IN_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"

namespace blue_pearl_bank
{

	class LogInFrame : public wxFrame
	{

	public:

		LogInFrame();

	private:

		void setUpTitlePanel();
		void setupMessagePanel();
		void setupEmailPanel();
		void setupPasswordPanel();
		void setupButtons();
		void setupAuthorInfo();
		void activateButtons();

		//*** Button Action

		void onClickCreateAccount(wxCommandEvent& event);
		void onClickLogIn(wxCommandEvent& event);

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

		wxButton createAccountButton;
		wxButton logInButton;

		//*** Author Info

		wxStaticText authorInfo;

	};
}

#endif