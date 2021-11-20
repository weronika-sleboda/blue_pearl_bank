#include "main_application.h"
#include "frame_controller.h"

namespace blue_pearl_bank
{

	wxIMPLEMENT_APP(MainApplication);

	bool MainApplication::OnInit()
	{

		FrameController::frameController().showStarterFrame();

		return true;

	}

}
