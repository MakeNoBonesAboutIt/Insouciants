#include <stdio.h>
#include "../manapool.h"

int main ()
{
	int res;
	struct manapool_t pool = { 1 };
	struct card_t card = {"name_of_card", 3,5,3};
	
	add_mana(&pool, 3);
	printf("pool  = %d\n", pool.mana);
		
	res = can_put_card(&card, &pool);
	printf("res can_put_card = %d\n", res);
	
	res = remove_mana(&pool, 2);
	printf("res remove_mana = %d\n", res);
	printf("pool = %d\n", pool.mana);
	
	res = can_put_card(&card, &pool);
	printf("res can_put_card = %d\n", res);
	
	res = remove_mana(&pool, 3);
	printf("res remove_mana= %d\n", res);
	printf("pool = %d\n", pool.mana);
		
	return 0;
}
