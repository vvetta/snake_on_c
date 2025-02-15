#include <stdio.h>
#include <unistd.h>

#include "game_field_lib/game_field.h"
#include "snake_lib/snake.h"
#include "input_lib/input.h"
#include "main.h"

#define HEIGHT 25
#define WIDTH 80
#define START_SNAKE_LENGTH 3

int main(void) {
	int error_flag = 0;

	// Инициализация игрового поля.
	char **game_field = NULL;
	char game_field_symbol = '.';
	game_field = (char**)create_game_field(HEIGHT, WIDTH); 	
	if (game_field == NULL) {
		error_flag = 1;	
	}
	fill_game_field(game_field, HEIGHT, WIDTH, game_field_symbol);

	// Инициализация змеи.	
	char *snake = NULL;
	char snake_body_symbol = '@';	
	snake = (char*)create_snake(START_SNAKE_LENGTH);
	if (snake == NULL) {
		error_flag = 1;
	}
	fill_snake(snake, START_SNAKE_LENGTH, snake_body_symbol);


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
	// Цикл обновления экрана.	
		
	char user_ch = '0';
	char snake_dir = '0';

	add_snake_to_game_field(game_field, HEIGHT, WIDTH, snake, START_SNAKE_LENGTH);

	while (user_ch != 'q') {

		//update_game_field(game_field, snake, START_SNAKE_LENGTH, fruit_symbol, HEIGHT, WIDTH, snake_dir);	
		print_game_field(game_field, HEIGHT, WIDTH);

		// Ожидаем от пользователя нажатия на кнопку.
		user_ch = get_game_char();
		if (user_ch == 'A' || user_ch == 'B' || user_ch == 'C' || user_ch == 'D') {
			snake_dir = user_ch;
		}
		printf("Была нажата клавиша: %c", user_ch);


		// Задержка обновления экрана
		sleep(1);

	}		

	return 0;
}

int update_game_field(char **game_field, char *snake, int start_snake_length, char fruit_symbol, int height, int width, char snake_dir) {

	int snake_length = start_snake_length;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			
				

		}
	}

	return 0;
}





