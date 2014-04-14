#ifndef CARD_H
#define CARD_H

struct card_t
{
	char name[32];
	int attack;
	int life;
	int cost;
};

int attack(struct card_t*attacker, struct card_t*defender);

#endif
