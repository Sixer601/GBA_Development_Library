#pragma once

#include <tonc.h>
#include "sprite.h"

struct player 
{
	int x;
	int y;
	int state;
	int currentHealth;
	int totalHealth;
	OBJ_ATTR *sprite;
};

extern void SetPlayerSprite(struct player * pPlayer, OBJ_ATTR *pSprite, struct sprite *spriteData);

extern void SetPlayerLocation(struct player * pPlayer, OBJ_ATTR *pSprite, int x, int y);
