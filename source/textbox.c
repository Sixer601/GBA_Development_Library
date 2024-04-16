#include <stdlib.h>
#include <tonc.h>

#include "textbox.h"
#include "constants.h"

void SetTextBoxData(struct textbox * pTextBox, int textBoxTilesLen, const unsigned int textBoxTiles[], int textBoxPalLen, const unsigned short textBoxPal[])
{
	pTextBox->tBoxTilesLen = textBoxTilesLen;
	for(int i = 0; i < TBOXTILESLENGTH; i++)
	{
		pTextBox->tBoxTiles[i] = textBoxTiles[i];
	}
	pTextBox->tBoxPalLen = textBoxPalLen;
	for(int j = 0; j < TBOXPALLENGTH; j++)
	{
		pTextBox->tBoxPal[j] = textBoxPal[j];
	}
}

void CreateTextBox(struct textbox * pTextBox, int top, int bottom, int left, int right, CSTR text)
{
	pTextBox->top = top;
	pTextBox->bottom = bottom;
	pTextBox->left = left;
	pTextBox->right = right;
	pTextBox->visible = true;
	TSurface src, *dst= tte_get_surface();
	srf_init(&src, SRF_CHR4C, pTextBox->tBoxTiles, 240, 32, 4, (u16*)pTextBox->tBoxPal);
	srf_pal_copy(dst, &src, 16);
	schr4c_blit(dst, 0, 128, 240, 32, &src, 0, 0);

	REG_WIN0H= left<<8 | right;
	REG_WIN0V=  top<<8 | bottom;
	REG_WIN0CNT= WIN_ALL | WIN_BLD;
	REG_WINOUTCNT= WIN_ALL;

	REG_BLDCNT= (BLD_ALL&~BIT(0)) | BLD_BLACK;

	REG_DISPCNT |= DCNT_WIN0;

	tte_set_margins(left, top, right, bottom);
	tte_write(text);
}

void TextBoxIsVisible(struct textbox * pTextBox, bool isVisible)
{
	if(isVisible != pTextBox->visible)
	{
		if(isVisible == false)
		{
			// no longer show textbox
			REG_DISPCNT &= ~DCNT_BG0;
		}
		else
		{
			// show textbox
			REG_DISPCNT |= DCNT_BG0;
		}
		pTextBox->visible = isVisible;
	}
}
