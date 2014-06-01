#ifndef MANAPOOL_H
#define MANAPOOL_H

#include "card.h"

#define ERR_NOT_ENOUGH_MANA 1

struct manapool_t 
{
	int mana;
	int begin_turn_mana;
};

void add_mana (struct manapool_t *pool , int amount);

int remove_mana (struct manapool_t *pool , int amount);

int can_put_card (struct card_t *card_to_put, struct manapool_t *pool);

#endif
