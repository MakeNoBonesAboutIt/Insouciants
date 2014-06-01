#include "manapool.h"

void add_mana (struct manapool_t *pool , int amount)
{
	pool->mana += amount;
	if (pool->mana > 10)
		pool->mana = 10;
}

int remove_mana (struct manapool_t *pool , int amount)
{
	if (pool->mana < amount) return ERR_NOT_ENOUGH_MANA;
	pool->mana -= amount;
	return 0;
}

int can_put_card (struct card_t *card_to_put, struct manapool_t *pool)
{
	return card_to_put->cost <= pool->mana;
}
