#include"card.h"

/*Funkciq attack(ne vru6ta realnoto HP sled bitkata)
Vru6ta 0 ako sa umreli i 2te, 1 ako attacker e jiv,
2 ako defender e jiv, 3 ako i dvete sa jivi*/
int attack(struct card_t*attacker, struct card_t*defender)
{
	if(attacker->attack >= defender->life)
	{	
		defender->life = defender->life - attacker->attack;
		if(defender->attack >= attacker->life)
		{
			attacker->life = attacker->life - defender->attack;	
			return 0;
		}
		else
		{
			attacker->life = attacker->life - defender->attack;
			return 1;
		}
	}
	else
	{	
		defender->life = defender->life - attacker->attack;
		if(defender->attack >= attacker->life)
		{	
			attacker->life = attacker->life - defender->attack;
			return 2;
		}
		else
		{	attacker->life = attacker->life - defender->attack;
			return 3;
		}
	}
}
