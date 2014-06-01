#ifdef BOARD_H
#define BOARD_H

#include "player.h"

struct board_t
{
	struct player_t player_1;
	struct player_t player_2;		
	struct deck_t board_1;
	struct deck_t board_2;
	int turn;
};

/*Returns 0 if can play, 1 if not enough cards, 2 if not enough mana, 3 if space taken*/
int can_play_card(struct board_t *board, int first_pl, int card, int num_lane);

/*Puts a card on the board, removes from hand, removes mana*/
int play_card(struct board_t *board, int first_pl, int card, int num_lane); 

/*Both players have ended their turn*/
void turn_end(struct board_t *board, int first_pl);

/*Prints board and all messagaes*/
void print_board(struct board_t *board);

/*Changes player once in a turn, after that call turn_end*/
void change_player(int first_pl);

#endif
