#include "board.h"
#include <stdio.h>

int can_play_card(struct board_t *board, int card, int num_lane)
{	
	struct player_t* player;
	struct deck_t* board_c;
	if (board->player_turn == 1)
	{
		player = &board->player_1;
		board_c = &board->board_1;
	}
	else
	{
		player = &board->player_2;
		board_c = &board->board_2;
	}
	if (player->player_hand.n < card)
		return 1;
	if (can_put_card(&player->player_hand.cards[card], &player->player_mana ) == 0)
	{
		if (board_c->cards[num_lane-1].life == 0)
			return 0;
		else
			return 3;
	}
	else 
		return 2;
}

int play_card(struct board_t *board, int card, int num_lane)
{	
	int i;
	struct card_t card_temp;
	struct player_t* player;
	struct deck_t* board_c;
	if (board->player_turn == 1)
	{
		player = &board->player_1;
		board_c = &board->board_1;
		board->player_1.player_mana.mana -= board->player_1.player_hand.cards[card-1].cost;
	}
	else
	{
		player = &board->player_2;
		board_c = &board->board_2;
		board->player_2.player_mana.mana -= board->player_2.player_hand.cards[card-1].cost;
	}
	card_temp = play_card_from_hand(player, card-1);
	board_c->cards[num_lane-1] = card_temp;
	return 0;
}

void change_player(struct board_t *board)
{
	struct card_t card;
	if (board->player_turn == 1)
	{		
		board->player_turn = 2;
		if (board->player_2.player_mana.begin_turn_mana + 1 <= 10)
			board->player_2.player_mana.begin_turn_mana ++;		
		board->player_2.player_mana.mana = board->player_2.player_mana.begin_turn_mana;
		draw_card(&board->player_2.player_deck, &card);
		push_card(card, &board->player_2.player_hand);
	}	
	else
	{
		board->player_turn = 1;
		if (board->player_1.player_mana.begin_turn_mana + 1 <= 10)
			board->player_1.player_mana.begin_turn_mana ++;
		board->player_1.player_mana.mana = board->player_1.player_mana.begin_turn_mana;
		draw_card(&board->player_1.player_deck, &card);
		push_card(card, &board->player_1.player_hand);
	}
}

void turn_end(struct board_t *board)
{
	board->turn ++;
	int i;
	for (i = 0; i <= 5; i++)
	{	
		if ((board->board_1.cards[i].attack == 0) && (board->board_1.cards[i].life == 0))
			board->player_1.player_hp -= board->board_2.cards[i].attack;
		if ((board->board_2.cards[i].attack == 0) && (board->board_2.cards[i].life == 0))
			board->player_2.player_hp -= board->board_1.cards[i].attack;
		attack(&board->board_1.cards[i], &board->board_2.cards[i]);
	}
	if (board->player_1.player_hp == 0)
	{
		printf("GG! Player 2 Wins!\n");
		return;
	}
	if (board->player_2.player_hp == 0)
	{
		printf("GG! Player 1 Wins!\n");
		return;
	}
	for (i=0; i<=5; i++)
	{
		if (board->board_1.cards[i].life <= 0)
		{
			board->board_1.cards[i].attack = 0;
			board->board_1.cards[i].life = 0;
		}
		if (board->board_2.cards[i].life <= 0)
		{
			board->board_2.cards[i].attack = 0;
			board->board_2.cards[i].life = 0;
		}
	}
}

void print_board(struct board_t *board)
{
	int i;
	printf("\n\n\n\n\n\n");
	printf("\nPlayer 2: %dHp, Mana %d/%d Turn:%d\n", 
		board->player_2.player_hp, 
		board->player_2.player_mana.mana, 
		board->player_2.player_mana.begin_turn_mana, 
		board->turn);
	printf("_____________________________________________________________\n");
	for (i = 0; i < 5; ++i)
		printf("| %2d/%2d(%2d) ",
			board->player_2.player_hand.cards[i].attack,
			board->player_2.player_hand.cards[i].life,
			board->player_2.player_hand.cards[i].cost);
	printf("|\n");
	printf("#############################################################\n");
	for (i = 0; i < 5; ++i)
		printf("#   %2d/%2d   ",
			board->board_2.cards[i].attack,
			board->board_2.cards[i].life);
	printf("#\n");
	for (i = 0; i < 5; ++i)
		printf("#   %2d/%2d   ",
			board->board_1.cards[i].attack, 
			board->board_1.cards[i].life);
	printf("#\n");
	printf("#############################################################\n");
	for (i = 0; i < 5; ++i)
		printf("| %2d/%2d(%2d) ",
			board->player_1.player_hand.cards[i].attack, 
			board->player_1.player_hand.cards[i].life,
			board->player_1.player_hand.cards[i].cost);
	printf("|\n");
	printf("_____________________________________________________________\n");
	printf("Player 1: %dHp, Mana %d/%d Turn:%d\n\n", 
		board->player_2.player_hp, 
		board->player_1.player_mana.mana, 
		board->player_1.player_mana.begin_turn_mana, 
		board->turn);
	printf("\n\n\n\n\n\n");
}
