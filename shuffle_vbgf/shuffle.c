#include "shuffle.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shuffle (struct deck_t*deck)
{
	srand(time(NULL));
	int random = rand();
	random = random%100000;
	int i,sh;
	struct deck_t first_half, second_half;
	for (sh=0; sh<20+random; sh++)
	{
		for(i=0; i<15; i++)
		{
			first_half.cards[i] = deck->cards[i];
			second_half.cards[i] = deck->cards[i+15];
		}

		for(i=0; i<15; i++)
		{	
			deck->cards[i*2] = first_half.cards[i];
			deck->cards[i*2+1] = second_half.cards[i];
		}
		if (sh%3==0)
		{
			for(i=0; i<15; i++)
			{
				second_half.cards[i] = deck->cards[i];
				first_half.cards[i] = deck->cards[i+15];
			}

			for(i=0; i<15; i++)
			{	
				deck->cards[i*2] = first_half.cards[i];
				deck->cards[i*2+1] = second_half.cards[i];
			}
		}
	}
}
