#include <stdio.h>
#include "../board.h"

int main()
{
    struct board_t board =
    {
   	{ /*Player_1*/
		{ /*player_deck*/
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
        	},

		{   /*player_mana*/
		1,
		0
		},

		{   /*player_hand*/
		0, {}
		},
		30 /*player_hp*/
    	},

   	{ /*Player_2*/
		{ /*player_deck*/
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
        	},

		{   /*player_mana*/
		1,
		0
		},

		{   /*player_hand*/
		0, {}
		},
		30  /*player_hp*/
	},
	
	{ /*board_1*/
	    5,
	    {
	        {"Sen'jin Shieldmasta",0,0,0},
	        {"Argent crusader",0,0,0},
	        {"Nat Pagle",0,0,0},
	        {"Ragnaros",0,0,0},
	        {"Faire Dragon",0,0,0},
	    }
	},

	{ /*board_2*/
	    5,
	    {
	        {"Sen'jin Shieldmasta",0,0,0},
	        {"Argent crusader",0,0,0},
	        {"Nat Pagle",0,0,0},
	        {"Ragnaros",0,0,0},
	        {"Faire Dragon",0,0,0},
	    }
	},
	0 /*turn*/,
	1 /*player_turn*/
	};

	int res;
	print_board(&board);

	change_player(&board);
	change_player(&board);
	change_player(&board);
	change_player(&board);
	change_player(&board);
	print_board(&board);



	/*Returns 0 if can play, 1 if not enough cards, 2 if not enough mana, 3 if space taken*/
	res = can_play_card(&board, 1, 5);
	printf("%d\n", res);

	/*Puts a card on the board, removes from hand, removes mana*/
	play_card(&board, 1, 5); 
	print_board(&board);

	change_player(&board);
	play_card(&board, 2, 5);
	print_board(&board);
	turn_end(&board);
	print_board(&board);

	change_player(&board);
	play_card(&board, 2, 4);
	change_player(&board);
	play_card(&board, 2, 5);
	print_board(&board);

	/*Both players have ended their turn*/
	turn_end(&board);
	print_board(&board);



	return 0;
}
