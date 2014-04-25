#include "deck.h"

int push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
	if(player_deck->n>=MAX_CARDS_IN_DECK) return 1;
	player_deck->cards[player_deck->n]=card_to_push;
	player_deck->n++;	
	return 0;
}

int draw_card(struct deck_t *player_deck, struct card_t *card)
{
	if(player_deck->n<=0) return 2;
	player_deck->n--;
	*card=player_deck->cards[player_deck->n];
	return 0;
}

int look_card(struct deck_t *player_deck, struct card_t *card)
{
	if(player_deck->n<=0) return 2;
	*card=player_deck->cards[player_deck->n-1];
	return 0;
}
