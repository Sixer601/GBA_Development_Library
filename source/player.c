#include <stdlib.h>
#include <tonc.h>
#include <string.h>
#include "player.h"
#include "sprite.h"

void SetPlayerSprite(struct player * pPlayer, OBJ_ATTR * obj_buffer, struct sprite * pSprite)
{
	memcpy(&tile_mem[4][0], pSprite->spriteTiles, pSprite->spriteTilesLen);
	memcpy(pal_obj_mem, pSprite->spritePal, pSprite->spritePalLen);

	oam_init(obj_buffer, 128);

	u32 tid= 0, pb= 0;
	pPlayer->sprite = obj_buffer;
	obj_set_attr(pPlayer->sprite,
		ATTR0_SQUARE,
		ATTR1_SIZE_32,
		ATTR2_PALBANK(pb) | tid);
}

void SetPlayerLocation(struct player * pPlayer, OBJ_ATTR * obj_buffer, int pX, int pY)
{
	u32 tid= 0, pb= 0;
	pPlayer->x = pX;
	pPlayer->y = pY;
	obj_set_pos(pPlayer->sprite, pPlayer->x, pPlayer->y);
	obj_buffer[0].attr2= ATTR2_BUILD(tid, pb, 0);
	oam_copy(oam_mem, obj_buffer, 1);
}
