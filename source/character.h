#pragma once

#include <tonc.h>
#include "sprite.h"

struct character
{
	int x;
	int y;
	int state;
	OBJ_ATTR *sprite;
};

extern void SetCharacterSprite(struct character *pCharacter, OBJ_ATTR *pSprite, struct sprite *spriteData);

extern void SetCharacterLocation(struct character *pCharacter, OBJ_ATTR *pSprite, int x, int y);
