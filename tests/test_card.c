#include<stdio.h>
#include<string.h>
#include "../card.h"

void print_card(struct card_t *card)
{
	printf("{'%s', at: %d, def: %d, cost: %d}\n", card->name, card->attack, card->life, card->cost);
}


int main()
{
	struct card_t card_1, card_2;
	int result;
	strcpy(card_1.name, "c1");
	card_1.cost  = 3;
	card_1.attack = 1;
	card_1.life = 1;
	strcpy(card_2.name, "2");
	card_2.cost  = 15;
	card_2.attack = 40;
	card_2.life = 10;
	print_card(&card_1);
	print_card(&card_2);
	result=attack(&card_1,&card_2);
	printf("%d\n", result);
	print_card(&card_1);
	print_card(&card_2);
	return 0;
}
