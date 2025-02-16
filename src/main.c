#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "game_field_lib/game_field.h"
#include "snake_lib/snake.h"
#include "input_lib/input.h"
#include "main.h"

#define HEIGHT 25
#define WIDTH 80
#define START_SNAKE_LENGTH 1

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
	char snake_body_symbol = '#';	
	char snake_head_symbol = '@';	
	snake = (char*)create_snake(START_SNAKE_LENGTH);
	if (snake == NULL) {
		error_flag = 1;
	}
	fill_snake(snake, START_SNAKE_LENGTH, snake_body_symbol, snake_head_symbol);


	// Символ фрукта.
	char fruit_symbol = 'F';

	// Основной цикл игры.
	if (error_flag != 1) {
		main_loop(game_field, snake, fruit_symbol, snake_body_symbol, game_field_symbol, snake_head_symbol);
	}	

	delete_snake(snake);
  delete_game_field(game_field, HEIGHT);

	return error_flag;
}

int main_loop(char **game_field, char *snake, char fruit_symbol, char snake_body_symbol,
		char game_field_symbol, char snake_head_symbol) {
	// Цикл обновления экрана.	
		
	char user_ch = '0';
	char snake_dir = '0';

	add_snake_to_game_field(game_field, HEIGHT, WIDTH, snake, START_SNAKE_LENGTH);

	while (user_ch != 'q') {

		update_game_field(game_field, snake, START_SNAKE_LENGTH, fruit_symbol, HEIGHT, WIDTH, snake_dir,
		snake_body_symbol, game_field_symbol, snake_head_symbol);	

		print_game_field(game_field, HEIGHT, WIDTH);

		// Ожидаем от пользователя нажатия на кнопку.
		user_ch = get_game_char();
		if (user_ch == 'A' || user_ch == 'B' || user_ch == 'C' || user_ch == 'D') {
			snake_dir = user_ch;
		}

		// Задержка обновления экрана
		//sleep(1);

	}		

	return 0;
}

int update_game_field(char **game_field, char *snake, int start_snake_length, char fruit_symbol, int height, int width, char snake_dir, char snake_body_symbol, char game_field_symbol, char snake_head_symbol) {

	int snake_length = start_snake_length;
	int count_fruit = 0;	

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
		
			if (game_field[y][x] == fruit_symbol) {
				count_fruit++;
			}

			if (snake_dir == 'C') {
				// Вправо	
				if (game_field[y][x] == snake_head_symbol && x != width - 1) {
					if (game_field[y][x+1] != snake_body_symbol) {
						game_field[y][x] = game_field_symbol;	
						game_field[y][x+1] = snake_head_symbol;
					}
					snake_dir = '0';
				}	
			} else if (snake_dir == 'A') {
				// Вверх	
				if (game_field[y][x] == snake_head_symbol && y != 0) {
					if (game_field[y-1][x] != snake_body_symbol) {
						game_field[y][x] = game_field_symbol;	
						game_field[y-1][x] = snake_head_symbol;
					}
					snake_dir = '0';
				}	
			} else if (snake_dir == 'B') {
				// Вниз
				if (game_field[y][x] == snake_head_symbol && y != height - 1) {
					if (game_field[y+1][x] != snake_body_symbol) {
						game_field[y][x] = game_field_symbol;
						game_field[y+1][x] = snake_head_symbol;
					}
					snake_dir = '0';
				}
			} else if (snake_dir == 'D') {
				// Влево
				if (game_field[y][x] == snake_head_symbol && x != 0) {
					if (game_field[y][x-1] != snake_body_symbol) {
						game_field[y][x] = game_field_symbol;
						game_field[y][x-1] = snake_head_symbol;
					}
					snake_dir = '0';
				}
			}
		}
	}
	
	if (count_fruit < 1) {
		add_fruit_to_game_field(game_field, fruit_symbol);
	}

	return 0;
}

int add_fruit_to_game_field(char **game_field, char fruit_symbol) {
	int random_col = rand() % WIDTH;
	int random_row = rand() % HEIGHT;

	game_field[random_row][random_col] = fruit_symbol;

	return 0;
}
