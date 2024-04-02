#pragma once

#include <tonc.h>
#include "constants.h"

struct background
{
	int bgTilesLen;
	unsigned int bgTiles[BGTILESLENGTH];
	int bgMapLen;
	unsigned short bgMap[BGMAPLENGTH];
	int bgPalLen;
	unsigned short bgPal[BGPALLENGTH];
};

extern void SetBackgroundData(struct background *pBackground, int tileLength, const unsigned int tiles[], int mapLength, const unsigned short map[], int palLength, const unsigned short pal[]);

extern void SetBackground(struct background *pBackground, int charblock, int screenblock);
