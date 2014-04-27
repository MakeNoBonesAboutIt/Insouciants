#include "deck.h"

int push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
	if(player_deck->n>=MAX_CARDS_IN_DECK) return ERR_EXHAUSTED_STACK_SIZE;
	player_deck->cards[player_deck->n]=card_to_push;
	player_deck->n++;	
	return 0;
}

int draw_card(struct deck_t *player_deck, struct card_t *card)
{
	if(player_deck->n<=0) return ERR_EMPTY_STACK;
	player_deck->n--;
	*card=player_deck->cards[player_deck->n];
	return 0;
}

int look_card(struct deck_t *player_deck, struct card_t *card)
{
	if(player_deck->n<=0) return ERR_EMPTY_STACK;
	*card=player_deck->cards[player_deck->n-1];
	return 0;
}
