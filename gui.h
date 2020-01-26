#include "game.h"
#include <stdio.h>
#include <stdlib.h>

#define PRINT_RULES 1
#define START_GAME 2
#define EXIT 3


/*
Function: display_menu;
Description: display menu for the game;
	@param void;
	@return void;
*/
void display_menu(void);

/*
Function: display_rules;
Description: dipslay the rules;
	@param void;
	@return void;
*/
void display_rules(void);

/*
Function: get_selection;
Description: gets the user selection for the main menu;
	@param void;
	@return the selection number;
*/
int get_selection(void);

/*
Function: determine_selection;
Description: determines what to do with the user selection;
	@param selection		user choice;
	@return void;
*/
void determine_selection(int selection);

/*
Function: display_scores;
Description: will display the current scores or any list
	is a chart for yahtzee;
	@param p1_scores[]		list 1;
	@param p2_scores[]		list 2;
	@return void;
*/
void display_scores(int p1_scores[], int p2_scores[]);

/*
Function: dipslay_roll;
Description: displays the rolls of the dice;
	@param die[]		the dice values;
	@return void;
*/
void display_roll(int die[]);

/*
Function: print_line;
Description: prints a line for, used in the display_scores;
	@param void;
	@return void;
*/
void print_line(void);

/*
Function: get_sum;
Description: gets the sum of a certain section in an array;
	@param scores[]		list to sum;
	@param start		starting point;
	@param end			ending point;
	@return sum of scores from start to end;
*/
int get_sum(int scores[], int start, int end);