#ifndef SHUFFLE_H
#define SHUFFLE_H

struct card_t
{
	char name[32];
	int cost;
	int attack;
	int life;
};

struct deck_t
{
	int n;	
	struct card_t cards[32];
};

void shuffle (struct deck_t*deck);

#endif
