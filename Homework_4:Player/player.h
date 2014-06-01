#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deck.h"
#include "manapool.h"

#define MAX_HP 30
#define MIN_HP 0

struct player_t
{
    struct deck_t player_deck;
    struct manapool_t player_mana;
    struct deck_t player_hand;
    int player_hp;
};

/*Returns 1 if HP=0*/
int change_hp(struct player_t *player, int hp);

struct card_t play_card_from_hand(struct player_t *player, int card);

void turn_begin(struct player_t *player);

#endif
