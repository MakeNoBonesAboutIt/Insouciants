#include "board.h"

int can_play_card(struct board_t *board, int first_pl, int card, int num_lane)
{	
	if(can_put_card = 0)
	{
		if (first_pl == 1)
		{
			if (board->player_1->player_hand.n < int card)
				return 1;
			if (board->board_1->cards[num_lane-1].life = 0)
				return 0;
			else
				return 3;
		}		
		else
			if (board->player_2->player_hand.n < int card)
				return 1;
			if (board->board_2->cards[num_lane-1].life = 0)
				return 0;
			else
				return 3;
	}
	else 
		return 2;
}

int play_card(struct board_t *board, int first_pl, int card, int num_lane)
{
	int i;
	if (first_pl == 1)
	{
		board->board_1.cards[num_lane-1] = board->player_1->player_hand.cards[card-1];
		remove_mana(board->player_1->player_mana, board->player_1->player_hand->cards[card-1].cost);
		for (i = card-1; i < board->player_1->player_hand.n; i++)
		{
			board->player_1->player_hand.cards[i-1] = board->player_1->player_hand.cards[i];
		}	
		board->player_1->player_hand.n --;
	}
	else
	{
		board->board_2.cards[num_lane-1] = board->player_2->player_hand.cards[card-1];
		remove_mana(board->player_2->player_mana, board->player_2->player_hand->cards[card-1].cost);
		for (i = card-1; i < board->player_2->player_hand.n; i++)
		{
			board->player_2->player_hand.cards[i-1] = board->player_2->player_hand.cards[i];
		}	
		board->player_2->player_hand.n --;
	}	
	return 0;
}

void change_player(int first_pl)
{
	if (first_pl == 1)
	{		
		first_pl = 2;
		if (board->player_2->player_mana.begin_turn_mana + 1 <= 10)
			board->player_2->player_mana.begin_turn_mana + 1;		
		board->player_2->player_mana.mana = board->player_2->player_mana.begin_turn_mana;
		draw_card(board->player_2->player_deck, board->player_2->player_hand->cards[board->player_2->player_hand.n]);
	}	
	else
	{
		first_pl = 1;
		if (board->player_1->player_mana.begin_turn_mana + 1 <= 10)
			board->player_1->player_mana.begin_turn_mana + 1;
		board->player_1->player_mana.mana = board->player_1->player_mana.begin_turn_mana;
		draw_card(board->player_1->player_deck, board->player_1->player_hand->cards[board->player_1->player_hand.n]);
	}
}

void turn_end(struct board_t *board, int first_pl)
{
	board.turn ++;
	int i;
	for (i = 0; i <= 5; i++)
	{	
		if (board->board_1->cards[i].attack == 0) & (board->board_1->cards[i].life == 0)
			board->player_1.player_hp -= board->board_2->cards[i].attack;
		if (board->board_2->cards[i].attack == 0) & (board->board_2->cards[i].life == 0)
			board->player_2.player_hp -= board->board_1->cards[i].attack;
		attack(board->board_1.cards[i], board->board_2.cards[i]);
	}
	if (board->player_1.player_hp == 0)
	{
		printf("GG! Player 2 Wins!\n");
		break;
	}
	if (board->player_2.player_hp == 0)
	{
		printf("GG! Player 1 Wins!\n");
		break;
	}
	for (i=0; i<=5; i++)
	{
		if (board->board_1->cards[i].life <= 0)
		{
			board->board_1->cards[i].attack = 0;
			board->board_1->cards[i].life = 0;
		}
		if (board->board_2->cards[i].life <= 0)
		{
			board->board_2->cards[i].attack = 0;
			board->board_2->cards[i].life = 0;
		}
	}
}

void print_board(struct board_t *board)
{
	printf("Player 2: %dHp, Mana %d/10 Turn:%d", board->player_2.player_hp, board->player_2->player_mana.begin_turn_mana, board.turn);
	printf("___________________________________________________");
	printf("|  %d|%d  |  %d|%d  |  %d|%d  |  %d|%d  |  %d|%d  |",
	board->player_2->player_hand->cards[0].attack, board->player_2->player_hand->cards[0].life,
	board->player_2->player_hand->cards[1].attack, board->player_2->player_hand->cards[1].life,
	board->player_2->player_hand->cards[2].attack, board->player_2->player_hand->cards[2].life,
	board->player_2->player_hand->cards[3].attack, board->player_2->player_hand->cards[3].life,
	board->player_2->player_hand->cards[4].attack, board->player_2->player_hand->cards[4].life,
	board->player_2->player_hand->cards[5].attack, board->player_2->player_hand->cards[5].life);
	printf("###################################################",);
	printf("#  %d|%d  #  %d|%d  #  %d|%d  #  %d|%d  #  %d|%d  #",	
	board->board_2->cards[0].attack, board->board_2->cards[0].life,
	board->board_2->cards[1].attack, board->board_2->cards[1].life,
	board->board_2->cards[2].attack, board->board_2->cards[2].life,
	board->board_2->cards[3].attack, board->board_2->cards[3].life,
	board->board_2->cards[4].attack, board->board_2->cards[4].life,
	board->board_2->cards[5].attack, board->board_2->cards[5].life);
	printf("#  %d|%d  #  %d|%d  #  %d|%d  #  %d|%d  #  %d|%d  #",
	board->board_1->cards[0].attack, board->board_1->cards[0].life,
	board->board_1->cards[1].attack, board->board_1->cards[1].life,
	board->board_1->cards[2].attack, board->board_1->cards[2].life,
	board->board_1->cards[3].attack, board->board_1->cards[3].life,
	board->board_1->cards[4].attack, board->board_1->cards[4].life,
	board->board_1->cards[5].attack, board->board_1->cards[5].life);
	printf("###################################################",);
	printf("|  %d|%d  |  %d|%d  |  %d|%d  |  %d|%d  |  %d|%d  |",
	board->player_1->player_hand->cards[0].attack, board->player_1->player_hand->cards[0].life,
	board->player_1->player_hand->cards[1].attack, board->player_1->player_hand->cards[1].life,
	board->player_1->player_hand->cards[2].attack, board->player_1->player_hand->cards[2].life,
	board->player_1->player_hand->cards[3].attack, board->player_1->player_hand->cards[3].life,
	board->player_1->player_hand->cards[4].attack, board->player_1->player_hand->cards[4].life,
	board->player_1->player_hand->cards[5].attack, board->player_1->player_hand->cards[5].life);
	printf("Player 1: %dHp, Mana %d/10 Turn:%d", board->player_2.player_hp, board->player_2->player_mana.begin_turn_mana, board.turn);

}
