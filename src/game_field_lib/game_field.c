#include "game_field.h"
#include <stdlib.h>
#include <stdio.h>


char **create_game_field(int height, int width) {
	char **game_field = NULL;
	game_field = (char**)malloc(height * sizeof(char*));
	if (game_field == NULL) {
		printf("Error! It was not possible to allocate memory for the playing field.");
	} else {
		for (int i = 0; i < height; i++) {
			game_field[i] = (char*)malloc(width * sizeof(char));
			if (game_field[i] == NULL) {
				printf("Error! It was not possible to allocate memory for the playing field.");
			}
		}
	}

	return game_field;
}

void delete_game_field(char **game_field, int height) {
	if (game_field == NULL) {
		printf("The memory has already been cleared!");
	} else {
		for (int i = 0; i < height; i++) {
			free(game_field[i]);		
		}
		free(game_field);
	}
}

void print_game_field(char **game_field, int height, int width) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			printf("%c", game_field[y][x]);
		}
		printf("\n");
	}
}

