#include <tonc.h>
#include <string.h>
#include "background.h"
#include "constants.h"

void SetBackgroundData(struct background *pBackground, int tileLength, const unsigned int tiles[], int mapLength, const unsigned short map[], int palLength, const unsigned short pal[])
{
	pBackground->bgTilesLen = tileLength;
	for(int i = 0; i < BGTILESLENGTH; i++)
	{
		pBackground->bgTiles[i] = tiles[i];
	}
	pBackground->bgMapLen = mapLength;
	for(int j = 0; j < BGMAPLENGTH; j++)
	{
		pBackground->bgMap[j] = map[j];
	}
	pBackground->bgPalLen = palLength;
	for(int k = 0; k < BGPALLENGTH; k++)
	{
		pBackground->bgPal[k] = pal[k];
	}
}

void SetBackground(struct background *pBackground, int charblock, int screenblock)
{
	memcpy(pal_bg_mem, pBackground->bgPal, pBackground->bgPalLen);
	memcpy(&tile_mem[charblock][0], pBackground->bgTiles, pBackground->bgTilesLen);
	memcpy(&se_mem[screenblock][0], pBackground->bgMap, pBackground->bgMapLen);

	REG_BG2CNT= BG_CBB(charblock) | BG_SBB(screenblock) | BG_4BPP | BG_REG_64x64;
	REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG2 | DCNT_BG0;
}
