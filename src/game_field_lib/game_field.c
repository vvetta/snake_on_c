#include "game_field.h"
#include <stdlib.h>
#include <stdio.h>


char **memory_allocation_for_game_field(int height, int width) {
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

void free_memory(char **game_field, int height) {
	if (game_field == NULL) {
		printf("The memory has already been cleared!");
	} else {
		for (int i = 0; i < height; i++) {
			free(game_field[i]);		
		}
		free(game_field);
	}
}

