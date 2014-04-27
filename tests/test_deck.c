#include <stdio.h>
#include <string.h>
#include "../deck.h"

void print_card(struct card_t *card)
{
	printf("{'%s', at: %d, def: %d, cost: %d}", card->name, card->attack, card->life, card->cost);
}

void print_deck(struct deck_t *deck) 
{
	int i;
	for(i=0; i < deck->n; i++)
	{
		print_card(&deck->cards[i]);
		printf("\n");
	}
	printf("------------------- N=%d\n", deck->n);
}

int main()
{
	int res;
	struct deck_t player1;
	struct deck_t player2 = { 0 };
	struct card_t card;
	struct card_t card1;
	struct card_t card2 = {"Sen'jin shieldmasta",3,5,4};

	strcpy(card.name, "Sen'jin shieldmasta");
	card.attack = 3;
	card.life = 5;
	card.cost = 4;

	strcpy(card1.name, "Argent Crusader");
	card1.attack = 1;
	card1.life = 1;
	card1.cost = 1;

	player1.n = 0;

	res = push_card(card, &player1);
	printf("push_card RETURNED: %d\n", res);
	print_deck(&player1);

	res = push_card(card1, &player1);
	printf("push_card RETURNED: %d\n", res);
	print_deck(&player1);

	res = draw_card(&player1, &card);
	printf("draw_card RETURNED: %d\n", res);
	print_deck(&player1);

	res = look_card(&player1, &card);
	printf("look_card RETURNED: %d\n", res);
	print_deck(&player1);

	res = draw_card(&player1, &card);
	printf("draw_card RETURNED: %d\n", res);
	print_deck(&player1);

	res = look_card(&player1, &card);
	printf("look_card RETURNED: %d\n", res);
	print_deck(&player1);

	res = draw_card(&player1, &card);
	printf("draw_card RETURNED: %d\n", res);
	print_deck(&player1);

	player1.n = MAX_CARDS_IN_DECK;
	res = push_card(card, &player1);
	printf("push_card RETURNED: %d\n", res);


	return 0;
}
