#include"card.h"
#include<stdio.h>

/*Funkciq attack(ne vru6ta realnoto HP sled bitkata)
Vru6ta 0 ako sa umreli i 2te, 1 ako attacker e jiv,
2 ako defender e jiv, 3 ako i dvete sa jivi*/
int attack(struct card_t*attacker, struct card_t*defender)
{
	if(attacker->attack >= defender->life)
		if(defender->attack >= attacker->life)
			return 0;
		else
			return 1;
	else
		if(defender->attack >= attacker->life)
			return 2;
		else
			return 3;
}

/*Glavnata funkciq sus primerni karti*/
int main()
{
	struct card_t card_1, card_2;
	int result;
	card_1.attack = 2;
	card_1.life = 3;
	card_2.attack = 4;
	card_2.life = 1;
	result=attack(&card_1,card_2);
	printf("%d\n", result);
	return 0;
}
