#include <stdio.h>
#include <string.h>
#include "../deck.h"

int main()
{
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
	push_card(card, &player1);
	printf("N = %d\n", player1.n);
	push_card(card1, &player1);
	printf("N = %d\n", player1.n);
	draw_card(&player1, &card);
	printf("N = %d\n", player1.n);
	look_card(&player1, &card);
	printf("N = %d\n", player1.n);
	return 0;
}
