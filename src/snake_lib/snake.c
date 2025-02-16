#include "snake.h"
#include <stdlib.h>
#include <stdio.h>


char *create_snake(int start_length) {
	char *snake = NULL;

	snake = (char*)malloc(start_length * sizeof(char));

	if (snake == NULL) {
		printf("Error! It was not possible to allocate memory for the snake.");	
	}	

	return snake;
}


char *resize_snake(char *snake_body, int new_snake_length) {
	char *snake = NULL;

	snake = (char*)realloc(snake_body, new_snake_length);

	if (snake == NULL) {
		printf("Error! It was not possible to allocate memory for the snake.");	
	}

	return snake;
}


void delete_snake(char *snake) {
	free(snake);
}


void fill_snake(char *snake, int snake_length, char snake_body_symbol, char snake_head_symbol) {
	// Заполняет тело змейки символами змейки.
	
	for (int i = 0; i < snake_length; i++) {
		snake[i] = snake_body_symbol;
	}

	snake[snake_length - 1] = snake_head_symbol;

}
