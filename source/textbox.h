#pragma once

#include <tonc.h>
#include "constants.h"

struct textbox
{
	int top;
	int bottom;
	int left;
	int right;
	bool visible;
	int tBoxTilesLen;
	unsigned int tBoxTiles[TBOXTILESLENGTH];
	int tBoxPalLen;
	unsigned short tBoxPal[TBOXPALLENGTH];
};

extern void SetTextBoxData(struct textbox * pTextBox, int textBoxTilesLen, const unsigned int textBoxTiles[], int textBoxPalLen, const unsigned short textBoxPal[]);

extern void CreateTextBox(struct textbox * pTextBox, int top, int bottom, int left, int right, CSTR text);

extern void TextBoxIsVisible(struct textbox * pTextBox, bool isVisible);
