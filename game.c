#include "game.h"
#include "gui.h"

void play_game(void) {
	int p1Scores[13] = { 0 }, p2Scores[13] = { 0 }, combo[13] = {0},
		die[5] = { 0 }, keep[5] = { 0 },
		round = 1, roll = 1, player = 1, done;

	while (round < 13) {
		// iterate through each roll
		done = 0;
		for (roll = 1; roll <= 3 && !done; roll++) {
			system("cls");
			printf("Round %d\n\nTotal player scores:\n", round);
			display_scores(p1Scores, p2Scores);
			printf("Player %d's turn\nRoll %d\n", player, roll);
			system("pause");

			//roll die
			roll_die(die, keep);

			if (player == 1) { // player 1
				get_combos(die, combo, p1Scores);
				printf("\n\nrolled the following combinations\n");
				display_scores(combo, p2Scores);
				display_roll(die);

				if (roll < 3) {
					done = prompt_player(combo, p1Scores);
					if (!done) {
						get_keep(keep);
					}
				}
				else {
					int s = get_combo(p1Scores, combo);
					p1Scores[s] = combo[s];
				}
			}
			else { // player 2
				get_combos(die, combo, p2Scores);
				printf("\nrolled the following combinations\n");
				display_scores(p1Scores, combo);
				display_roll(die);

				if (roll < 3) {
					done = prompt_player(combo, p2Scores);
					if (!done) {
						get_keep(keep);
					}
				}
				else {
					int s = get_combo(p2Scores, combo);
					p2Scores[s] = combo[s];
				}
			}
		}

		if (player == 2) { 
			round++;
			player--;
		}
		else {
			player++;
		}
	}

	end_game(p1Scores, p2Scores);
}

void end_game(int p1[], int p2[]) {
	int first = 0, second = 0;

	if (get_sum(p1, 0, 6) >= 63) {
		first = 35;
	}
	if (get_sum(p2, 0, 6) >= 63) {
		second = 35;
	}
	system("cls");
	display_scores(p1, p2);
	
	printf("Player one total: %d\n", first += get_sum(p1, 0, 13));
	printf("Player two total: %d\n", second += get_sum(p2, 0, 13));

	if (first > second) {
		printf("Player 1 is the winner!\n");
	}
	else {
		printf("Player 2 is the winner!\n");
	}
	system("pause");
}

void roll_die(int die[], int keep[]) {
	int dice;
	srand((unsigned)time(NULL));

	// get die combos
	for (dice = 0; dice < 5; dice++) {
		if (!keep[dice]) {
			die[dice] = rand() % 6 + 1;
		}
	}
}

void get_combos(int die[], int combo[], int scorecard[]) {
	int counter[7] = { 0 }, i;
	for (i = 0; i < 13; i++) {
		combo[i] = scorecard[i];
	}

	// get amount of each value
	for (i = 0; i < 5; i++) {
		counter[die[i]]++;
	}

	// first combinations
	for (i = 0; i < 6; i++) {
		if (combo[i] == 0) {
			combo[i] = counter[i + 1] * (i + 1);
		}
	}

	if (three_kind(counter) && !combo[6]) { // three of a kind
		combo[6] = calc_sum(die);
	}
	if (four_kind(counter) && !combo[7]) { // four of a kind
		combo[7] = calc_sum(die);
	}
	if (full_house(counter) && !combo[8]) { // full house
		combo[8] = 25;
	}
	if (sequence(counter) == 4 && !combo[9]) { // sequence of four
		combo[9] = 30;
	}
	if (sequence(counter) == 5 && !combo[10]) { // sequence of five
		combo[10] = 40;
	}
	if (!combo[11]) { // chance
		combo[11] = calc_sum(die);
	}
	if (yahtzee(counter) && !combo[12]) { // yahtzee
		combo[12] = calc_sum(die);
	}

}

int prompt_player(int combo[], int scores[]) {
	char answer = '\0';
	int s = 0, done = 0;
	do {
		printf("Do you want to use a combination or roll again? (y/n)");
		scanf(" %c", &answer);
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y') {
		s = get_combo(scores, combo);
		scores[s] = combo[s];
		done = 1;
	}

	return done;
}

int get_combo(int scores[], int combo[]) {
	int ans = 0;
	do {
		printf("Which combination do you want to keep (1-13): ");
		scanf("%d", &ans);
		if (combo[ans -1] == 0) {
			ans = 0;
			printf("This combo is 0\n");
		}
		else if (combo[ans - 1] == scores[ans - 1]) {
			ans = 0;
			printf("This combo is already choosen\n");
		}
	} while (ans < 1 || ans > 13);

	return --ans;
}

int calc_sum(int num[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += num[i];
	}
	return sum;
}

void get_keep(int keep[]) {
	int yes = 0;
	printf("Choose which dice to keep. (1) for keep (0) for roll\n");
	for (int i = 0; i < 5; i++) {
		printf("Dice %d:  ", i + 1);
		scanf("%d", &yes);
		keep[i] = yes;
	}
}

int three_kind(int num[]) {
	int yes = 0;
	for (int i = 1; i < 7; i++) {
		if (num[i] == 3) {
			yes = 1;
		}
	}

	return yes;
}

int four_kind(int num[]) {
	int yes = 0;
	for (int i = 1; i < 7; i++) {
		if (num[i] == 4) {
			yes = 1;
		}
	}
	return 0;
}

int full_house(int num[]) {
	int yes = 0, pair = 0, trio = 0;
	for (int i = 1; i < 7; i++) {
		if (num[i] == 3) {
			trio = 1;
		}
		if (num[i] == 2) {
			pair = 1;
		}
	}

	if (pair && trio) {
		yes = 1;
	}
	return yes;
}

int sequence(int num[]) {
	int length = 0, yes = 1, max = 0;

	for (int i = 1; i < 7; i++) {
		if (num[i] > 0) {
			length = 1;
			for (int j = i + 1; j < 7; j++) {
				if (num[j] > 0) {
					length++;
					if (length > max) {
						max = length;
					}
				}
				else {
					j = 7;
				}
			}
		}
	}

	return max;
}

int yahtzee(int num[]) {
	int yes = 0;
	for (int i = 1; i < 7; i++) {
		if (num[i] == 5) {
			yes = 1;
		}
	}

	return yes;
}
