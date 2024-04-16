#include <string.h>

#include <tonc.h>
#include "constants.h"
#include "player.h"
#include "character.h"
#include "sprite.h"
#include "background.h"
#include "textbox.h"

#include "dlgbox.h"
#include "border.h"
#include "map.h"
#include "playerSprite.h"
#include "npcSprite.h"

OBJ_ATTR obj_buffer[128];
int MAP_WIDTH = 208;
int MAP_HEIGHT = 206;

int main()
{
	irq_init(NULL);
	irq_add(II_VBLANK, NULL);

	// Init for text
	tte_init_chr4c(
		0,							// BG number.
		BG_CBB(0)|BG_SBB(11),		// BG control.
		0xF000,						// Screen-entry offset
		bytes2word(13,15,0,0),		// Color attributes.
		CLR_BLACK,					// Ink color
		&verdana9_b4Font,			// Verdana 9, with shade.
		(fnDrawg)chr4c_drawg_b4cts_fast);	// b4cts renderer, asm version
	tte_init_con();					// Initialize console IO

	struct sprite playerSprite;
	SetSpriteData(&playerSprite, playerSpriteTilesLen, playerSpriteTiles, playerSpritePalLen, playerSpritePal);

	struct player myPlayer;
	SetPlayerSprite(&myPlayer, &obj_buffer[0], &playerSprite);
	SetPlayerLocation(&myPlayer, &obj_buffer[0], 104, 64);

	struct sprite npcSprite;
	SetSpriteData(&npcSprite, npcSpriteTilesLen, npcSpriteTiles, npcSpritePalLen, npcSpritePal);

	//struct character npc1;
	//SetCharacterSprite(&npc1, &obj_buffer[16], &npcSprite);
	//SetCharacterLocation(&npc1, &obj_buffer[16], 168, 96);

	struct background map;
	SetBackgroundData(&map, mapTilesLen, mapTiles, mapMapLen, mapMap, mapPalLen, mapPal);
	SetBackground(&map, 2, 12);

	struct textbox tBox;
	SetTextBoxData(&tBox, dlgboxTilesLen, dlgboxTiles, dlgboxPalLen, dlgboxPal);

	int x = 0;
	int y = 0;
	int xdir;
	int ydir;
	int moveDelay = 0;
	while(1)
	{
		vid_vsync();
		key_poll();
		xdir = key_tri_horz();
		ydir = key_tri_vert();

		if(moveDelay <= 0)
		{
			if((x + 16 * xdir) >= -96 && (x + 16 * xdir) <= 112)
			{
				x = x + 16 * xdir;
			}
			if((y + 16 * ydir) >= -32 && (y + 16 * ydir) <= 144)
			{
				y = y + 16 * ydir;
			}
			moveDelay = MOVEDELAYMAX;
		}
		else
		{
			moveDelay--;
		}

		if(x == COMPUTERX && y == COMPUTERY)
		{
			TextBoxIsVisible(&tBox, true);
			CreateTextBox(&tBox, 132, 232, 8, 156, "#{P}This is a computer.");
		}
		else
		{
			TextBoxIsVisible(&tBox, false);
		}

		REG_BG2HOFS = x;
		REG_BG2VOFS = y;
	}

	return 0;
}
