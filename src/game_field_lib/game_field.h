
char **create_game_field(int height, int width);
void delete_game_field(char **game_field, int height);
void print_game_field(char **game_field, int height, int width);
void add_snake_to_game_field(char **game_field, int height, int width, char *snake, int snake_length);
void fill_game_field(char **game_filed, int height, int width, char field_symbol);

