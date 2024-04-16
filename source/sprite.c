#include <tonc.h>

#include "sprite.h"

void SetSpriteData(struct sprite *pSprite, int tileLength, const unsigned int tiles[], int palLength, const unsigned short pal[])
{
	pSprite->spriteTilesLen = tileLength;
	for(int i = 0; i < 128; i++)
	{
		pSprite->spriteTiles[i] = tiles[i];
	}
	pSprite->spritePalLen = palLength;
	for(int j = 0; j < 256; j++)
	{
		pSprite->spritePal[j] = pal[j];
	}
}
