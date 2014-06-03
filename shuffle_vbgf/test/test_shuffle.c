#include "../shuffle.h"
#include <stdio.h>

void print_card(struct card_t *card)
{
	printf("{'%s', at: %d, def: %d, cost: %d}", card->name, card->attack, card->life, card->cost);
}

void print_deck(struct deck_t *deck) 
{
	printf("\n");
	int i;
	for(i=0; i < deck->n; i++)
	{
		print_card(&deck->cards[i]);
		printf("\n");
	}
	printf("------------------- N=%d\n\n", deck->n);
}

int main ()
{
	struct deck_t deck =
        {
            30,
            {
                {"Sen'jin Shieldmasta",3,5,4},
                {"Argent crusader",1,1,1},
                {"Nat Pagle",0,4,2},
                {"Ragnaros",8,8,8},
                {"Faire Dragon",3,2,2},
                {"Sen'jin Shieldmasta",3,5,4},
                {"Frostwolf Warlord",4,4,5},
                {"Ysera",4,12,9},
                {"Argent Protector",2,2,2},
                {"Doomhammer",2,8,5},
                {"Murlock Tidehunter",2,1,1},
                {"Defender of Argus",2,3,4},
                {"Stormwind Champion",6,6,7},
                {"Flame imp",3,2,1},
                {"Deathwing",12,12,10},
                {"Stone Giant",8,8,8},
                {"Molten giant",8,8,8},
                {"Al Akir",3,5,8},
                {"Dire Wolf Alpha",2,2,2},
                {"Defender of Argus",2,3,4},
                {"Sunwalker",4,5,6},
                {"Leroy Jenkins",6,2,4},
                {"Desniq krak na Stella",12,12,1},
                {"Leviq krak na Stella",12,12,1},
                {"Elven Archer",1,1,1},
                {"Elven Archer",1,1,1},
                {"Dire Wolf Alpha",2,2,2},
                {"Faceless Manipulator",3,3,5},
                {"BBBbBBbasheva",10,10,3},
                {"Hineca",3,10,2}
            }
	};
	
	print_deck(&deck);
	shuffle(&deck);
	print_deck(&deck);

	return 0;
}
