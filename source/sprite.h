#pragma once

#include <tonc.h>

struct sprite 
{
	int spriteTilesLen;
	unsigned int spriteTiles[128];
	int spritePalLen;
	unsigned short spritePal[256];
};

extern void SetSpriteData(struct sprite *pSprite, int tileLength, const unsigned int tiles[], int palLength, const unsigned short pal[]);
