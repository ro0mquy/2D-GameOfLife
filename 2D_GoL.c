#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define PLUS1 2
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



		
		sum = cell [!switcher] [78] + cell [!switcher] [79] + cell [!switcher] [1] + cell [!switcher] [2];

		if (sum == PLUS1 || sum == PLUS2) {
			cell [switcher] [0] = 1;
			printf ("%c", OUTPUT);
		}
		else {
			cell [switcher] [0] = 0;
			printf (" ");
		}


		sum = cell [!switcher] [79] + cell [!switcher] [0] + cell [!switcher] [2] + cell [!switcher] [3];

		if (sum == PLUS1 || sum == PLUS2) {
			cell [switcher] [1] = 1;
			printf ("%c", OUTPUT);
		}
		else {
			cell [switcher] [1] = 0;
			printf (" ");
		}		
		

		for (i = 2; i < 78; ++i) {
			sum = cell [!switcher] [i-2] + cell [!switcher] [i-1] + cell [!switcher] [i+1] + cell [!switcher] [i+2];

			if (sum == PLUS1 || sum == PLUS2) {
				cell [switcher] [i] = 1;
				printf ("%c", OUTPUT);
			}
			else {
				cell [switcher] [i] = 0;
				printf (" ");
			}
		}


		sum = cell [!switcher] [76] + cell [!switcher] [77] + cell [!switcher] [79] + cell [!switcher] [0];

		if (sum == PLUS1 || sum == PLUS2) {
			cell [switcher] [78] = 1;
			printf ("%c", OUTPUT);
		}
		else {
			cell [switcher] [78] = 0;
			printf (" ");
		}

		sum = cell [!switcher] [77] + cell [!switcher] [78] + cell [!switcher] [70] + cell [!switcher] [1];

		if (sum == PLUS1 || sum == PLUS2) {
			cell [switcher] [79] = 1;
			printf ("%c", OUTPUT);
		}
		else {
			cell [switcher] [79] = 0;
			printf (" ");
		}





		input = '´';
		if (_kbhit()) 
			input = _getch ();

		if (input == ' ') 
			_getch ();

		if (input == 27)
			break;

		if (input == '\r')
			goto start;
	}

	_getch ();
	return 0;
}
