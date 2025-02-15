#include <stdio.h>

char get_game_char() {

	char result;
	char input[3];

	input[0] = getchar();

	// Если это стрелочка.
	if (input[0] == '\x1B') {
		input[1] = getchar();
		input[2] = getchar();
	
		// A - вверх
		// B - вниз
		// C - вправо
		// D - влево
		
		result = input[2];
	} else {
		if (input[0] == 'A' && input[0] == 'B' && input[0] == 'C' && input[0] == 'D') {
			input[0] = '0';
		}
		result = input[0];
	}

	return result;
}
