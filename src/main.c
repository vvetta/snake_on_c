#include <stdio.h>

#include "game_field_lib/game_field.h"
#include "snake_lib/snake.h"
#include "main.h"

#define HEIGHT 25
#define WIDTH 80
#define START_SNAKE_LENGTH 3

int main(void) {
	int error_flag = 0;

	// Инициализация игрового поля.
	char **game_field = NULL;
	game_field = (char**)create_game_field(HEIGHT, WIDTH); 	
	if (game_field == NULL) {
		error_flag = 1;	
	}

	// Инициализация змеи.	
	char *snake = NULL;
	char snake_body_symbol = '@';	
	snake = (char*)create_snake(START_SNAKE_LENGTH, snake_body_symbol);
	if (snake == NULL) {
		error_flag = 1;
	}

	// Символ фрукта.
	char fruit_symbol = 'F';

	// Основной цикл игры.
	if (error_flag != 1) {
		main_loop(game_field, snake, fruit_symbol);
	}	

	delete_snake(snake);
  delete_game_field(game_field, HEIGHT);

	return error_flag;
}

int main_loop(char **game_field, char *snake, char fruit_symbol) {

	char user_ch = '0';

	while (user_ch != 'q') {

		

	}		

	return 0;
}
