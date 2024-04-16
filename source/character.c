#include <stdlib.h>
#include <tonc.h>
#include <string.h>
#include "character.h"
#include "sprite.h"

void SetCharacterSprite(struct character * pCharacter, OBJ_ATTR * obj_buffer, struct sprite * pSprite)
{
	memcpy(&tile_mem[4][0], pSprite->spriteTiles, pSprite->spriteTilesLen);
	memcpy(pal_obj_mem, pSprite->spritePal, pSprite->spritePalLen);

	u32 tid= 0, pb= 0;
	pCharacter->sprite = obj_buffer;
	obj_set_attr(pCharacter->sprite,
		ATTR0_SQUARE,
		ATTR1_SIZE_32,
		ATTR2_PALBANK(pb) | tid);
}

void SetCharacterLocation(struct character * pCharacter, OBJ_ATTR * obj_buffer, int pX, int pY)
{
	u32 tid= 0, pb= 0;
	pCharacter->x = pX;
	pCharacter->y = pY;
	obj_set_pos(pCharacter->sprite, pCharacter->x, pCharacter->y);
	obj_buffer[16].attr2= ATTR2_BUILD(tid, pb, 0);
	oam_copy(oam_mem, obj_buffer, 1);
}
