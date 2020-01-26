#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <math.h>

/*
Function: play_game;
Description: where the game play is at;
	@param void;
	@return void;
*/
void play_game(void);

/*
Function: end_game;
Description: show the results of the game;
	@param p1	player 1 scores
	@param p2	player 2 scores
	@return void;
*/
void end_game(int p1[], int p2[]);

/*
Function: roll_die;
Description: rolling the dice;
	@param die[]	the list of dice throws;
	@param keep[]	Which dice to keep and throw;
	@return void;
*/
void roll_die(int die[], int keep[]);

/*
Function: get_combos;
Description: Will get the many of the combos possible with
	the dice rolls;
	@param die[]	dice values;
	@param combo[]	list of combos;
	@param scorecard[]	player scores;
	@return void;
*/
void get_combos(int die[], int combo[], int scorecard[]);

/*
Function: prompt_player;
Description: Will prompt the player to roll again or use a combination;
	@param combo[]		list of combos;
	@param scores[]		list of player scores;
	@return the players choice;
*/
int prompt_player(int combo[], int scores[]);

/*
Function: get_combo;
Description: get the combo the user wants to lock in;
	@param scores[]		player scores;
	@param combo[]		list of combos;
	@return combo number;
*/
int get_combo(int scores[], int combo[]);

/*
Function: calc_sum;
Description: get the sum of die;
	@param num[]	list to sum up;
	@return the sum;
*/
int calc_sum(int num[]);

/*
Function: get_keep;
Description: asks which dice to keep;
	@param keep[]	list of dice to keep;
	@return void;
*/
void get_keep(int keep[]);

/*
Function: three_kind;
Description: checks for 3 of a kind;
	@param num[]	list to check;
	@return true or false;
*/
int three_kind(int num[]);

/*
Function: four_kind;
Description: checks for 4 of a kind;
	@param num[]	list to check;
	@return true or false;
*/
int four_kind(int num[]);

/*
Function: full_house;
Description: checks for 3 of a kind and a pair;
	@param num[]	list to check;
	@return true or false;
*/
int full_house(int num[]);

/*
Function: sequence;
Description: will check the list for a sequence of numbers;
	@param num[]	the list to check;
	@return length of sequence;
*/
int sequence(int num[]);

/*
Function: yahtzee;
Description: checks for a yahtzee combo;
	@param num[]	list to check;
	@return true or false;
*/
int yahtzee(int num[]);