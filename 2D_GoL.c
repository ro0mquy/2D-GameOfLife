#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define PLUS1 2				// Tuning Parameters
#define PLUS2 4
#define OUTPUT 219

void sleepx (int milliseconds) {

	clock_t start, act;
	int dif;

	start = clock ();

	while (1) {
		act = clock ();
		dif = act - start;
		
		if (dif > milliseconds - 9 && dif < milliseconds + 9){
			break;
		}
		else if (dif > 1000){
			break;
		}
	}
}


int main () {

	_textcolor (12);
	srand (time (0));
	int cell [2] [80];
	int switcher = 0;
	int line = 1;
	int sum;
	int i;
	char input;

	start:
	_clrscr ();
	switcher = 0;
	line = 1;

	for (i = 0; i < 80; ++i) {
		cell [0] [i] = 0;
		cell [1] [i] = 0;
	}

	_gotoxy (1, line);
	for (i = 0; i < 80; ++i) {
		cell [switcher] [i] = rand () % 2;
		
		if (cell [switcher] [i] == 1) {
			printf ("%c", OUTPUT);
		}
		else {
			printf (" ");
		}
	}

	while (1) {
		sleepx (500);

		switcher = !switcher;
		++line;
		_gotoxy (1, line);



		for (i = 0; i < 80; ++i) {
			sum = cell [!switcher] [(i-2) % 80] + cell [!switcher] [(i-1) % 80] + cell [!switcher] [(i+1) % 80] + cell [!switcher] [(i+2) % 80];

			if (sum == PLUS1 || sum == PLUS2) {
				cell [switcher] [i] = 1;
				printf ("%c", OUTPUT);
			}
			else {
				cell [switcher] [i] = 0;
				printf (" ");
			}
		}


		

		if (_kbhit()) {
			input = _getch ();

			if (input == ' ') 
				_getch ();

			else if (input == 27)
				break;

			else if (input == '\r')
				goto start;
		}
	}

	_getch ();
	return 0;
}
