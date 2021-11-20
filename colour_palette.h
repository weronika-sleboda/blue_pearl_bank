#ifndef COLOUR_PALETTE_H
#define COLOUR_PALETTE_H

#include <wx/wx.h>

namespace blue_pearl_bank 
{

	struct ColourPalette
	{

		const wxColour const lightSteel;
		const wxColour const steel;
		const wxColour const midSteel;
		const wxColour const darkSteel;
		const wxColour const galactic;
		const wxColour const red;

		ColourPalette() :

			lightSteel { 230, 239, 255 } ,
			steel { 113, 130, 143 } ,
			midSteel{ 113, 120, 133 } ,
			darkSteel { 71, 86, 97 } ,
			galactic { 51, 56, 77 } ,
			red { 94, 17, 1 }

		{}

	};

}

#endif