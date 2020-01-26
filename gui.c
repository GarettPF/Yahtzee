#include "gui.h"

void display_menu(void) {
	system("cls");
	printf("-- Welcome To Yahtee --\n");
	printf("1. Print Game Rules\n");
	printf("2. Start a Game of Yahtzee\n");
	printf("3. Exit\n");
}

void display_rules(void) {
	printf("-- Rules --\n\n\n");
	printf("The scorecard used for Yahtzee is composed of two sections.\n");
	printf("A upper sectionand a lower section.A total of thirteen boxes\n");
	printf("or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing\n");
	printf("the value of the dice matching the faces of the box.If a player\n");
	printf("rolls four 3's, then the score placed in the 3's box is the sum\n");
	printf("of the dice which is 12. Once a player has chosen to score a box,\n");
	printf("it may not be changedand the combination is no longer in play\n");
	printf("for future rounds.If the sum of the scores in the upper section\n");
	printf("is greater than or equal to 63, then 35 more points are added to\n");
	printf("the players overall score as a bonus.The lower section contains a\n");
	printf("number of poker like combinations. See the rules provided below : \n\n");
	printf("|%-20s|%-25s|%-25s|\n", "Name", "Combination", "Score");
	printf("|%-20s|%-25s|%-25s|\n", "3 of a kind", "3 dice with the same face", "Sum of all dice");
	printf("|%-20s|%-25s|%-25s|\n", "4 of a kind", "4 dice with the same face", "Sum of all dice");
	printf("|%-20s|%-25s|%-25s|\n", "Full House", "one pair and 3 of a kind", "25");
	printf("|%-20s|%-25s|%-25s|\n", "Small straight", "A sequence of 4 dice", "30");
	printf("|%-20s|%-25s|%-25s|\n", "Large straight", "A sequence of 5 dice", "40");
	printf("|%-20s|%-25s|%-25s|\n", "Yahtzee", "5 dice with the same face", "50");
	printf("|%-20s|%-25s|%-25s|\n", "Chance", "for an roll", "Sum of all dice");
	system("pause");
}

int get_selection(void) {
	int option = 0;
	do {
		display_menu();
		scanf("%d", &option);
	} while (option < PRINT_RULES || option > EXIT);
	return option;
}

void determine_selection(int selection) {
	system("cls");

	switch (selection) {
	case PRINT_RULES:
		display_rules();
		break;

	case START_GAME:
		play_game();
		break;
	}
}

void display_scores(int p1_scores[], int p2_scores[]) {
	int i = 0;
	char combos[15][20] = {
		"1. Ones", "2. Twos", "3. Threes", "4. Fours", "5. Fives", "6. Sixes",
		"Sum", "Bonus",
		"7. Three-of-a-kind", "8. Four-of-a-kind", "9. Full house",
		"10. Small straight", "11. Large straight", "12. Chance", "13. YATZY"
	};

	printf("%-20s|%-20s|%-20s|\n", "  Combinations", "  Player-1", "  Player-2");
	print_line();

	// upper combination section
	for (i = 0; i < 6; i++) {
		printf("%-20s|%-20d|%-20d|\n", combos[i], p1_scores[i], p2_scores[i]);
	}
	print_line();

	// total of upper combos
	int first = 0, second = 0;
	if (get_sum(p1_scores, 0, 6) >= 63) {
		first = 35;
	}
	if (get_sum(p2_scores, 0, 6) >= 63) {
		second = 35;
	}
	printf("%-20s|%-20d|%-20d|\n", combos[i++],
		get_sum(p1_scores, 0, 6), get_sum(p2_scores, 0, 6));
	printf("%-20s|%-20d|%-20d|\n", combos[i], first, second);
	print_line();

	// lower combination section
	for (i = 8; i < 15; i++) {
		printf("%-20s|%-20d|%-20d|\n", combos[i], p1_scores[i - 2], p2_scores[i - 2]);
	}
	print_line();

	// total of lower combos
	printf("%-20s|%-20d|%-20d|\n", "TOTAL",
		get_sum(p1_scores, 7, 13), get_sum(p2_scores, 7, 13));
	print_line();
}

void display_roll(int die[]) {
	printf("Rolled: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", die[i]);
	}
	printf("\n");
}

void print_line(void) {
	for (int i = 1; i <= 64; i++) {
		if (i % 21 == 0) {
			printf("+");
		}
		else if (i == 64) {
			printf("\n");
		}
		else {
			printf("-");
		}
	}
}

int get_sum(int scores[], int start, int end) {
	int sum = 0;
	for (int i = start; i < end; i++) {
		sum += scores[i];
	}
	return sum;
}
