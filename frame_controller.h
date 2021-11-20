#ifndef FRAME_CONTROLLER_H
#define FRAME_CONTROLLER_H

namespace blue_pearl_bank
{

	class StarterFrame;
	class LogInFrame;
	class AccountCreatorFrame;
	class BankFrame;

	class FrameController
	{

	public:

		static FrameController& frameController();

	public:

		~FrameController();

	public:

		void showStarterFrame();
		void showLogInFrame();
		void showAccountCreatorFrame();
		void showBankFrame();

	private:

		FrameController();
		FrameController(FrameController&) = delete;
		FrameController(FrameController&&) = delete;
		FrameController& operator=(FrameController&) = delete;
		FrameController& operator=(FrameController&&) = delete;

	private:

		StarterFrame* starterFrame;
		LogInFrame* logInFrame;
		AccountCreatorFrame* accountCreatorFrame;
		BankFrame* bankFrame;

	};

}

#endif