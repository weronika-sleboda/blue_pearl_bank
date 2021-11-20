#ifndef STARTER_FRAME_H
#define STARTER_FRAME_H

#include <wx/wx.h>
#include "colour_palette.h"

namespace blue_pearl_bank
{

	class StarterFrame : public wxFrame
	{

	public:

		StarterFrame();

	private:

		void setUpTitlePanel();
		void setupMessagePanel();
		void setupConnectButton();
		void setupAuthorInfo();
		void activateConnectButton();
		void showWaitForConnectionMessage();

		//*** Button Action

		void onClickConnectToServer(wxCommandEvent& event);

	private:

		ColourPalette colour;
		bool buttonClicked;

	private:

		//*** Title Panel

		wxPanel titleBorderPanel;
		wxPanel titlePanel;
		wxStaticText title;

		//*** MessagePanel

		wxPanel messageBorderPanel;
		wxPanel messagePanel;
		wxStaticText message;

		//*** Button

		wxButton connectButton;

		//*** Author Info

		wxStaticText authorInfo;

	};

}

#endif