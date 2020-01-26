/*
	Author: Garett Pascual-Folster
	Date Created: 10/7/2019
	Description: A game of Yahtzees.
		Have mercy on me James ;(
		this was hard

*/

#include "game.h"
#include "gui.h"

int main(void) {

	int isPlaying = 1, option = 0;

	while (isPlaying) {
		option = get_selection();
		determine_selection(option);
		if (option == EXIT) {
			isPlaying = 0;
		}
	}

	printf("Come again!\n");

	return 0;
}