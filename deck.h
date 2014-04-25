#ifndef DECK_H
#define DECK_H
#include "card.h"
#define MAX_CARDS_IN_DECK (40)

struct deck_t
{	
	int n;
	struct card_t cards[MAX_CARDS_IN_DECK];
};

int push_card(struct card_t card_to_push, struct deck_t *player_deck);
int draw_card(struct deck_t *player_deck, struct card_t *card);
int look_card(struct deck_t *player_deck, struct card_t *card);

#endif
