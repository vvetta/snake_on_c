
COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
BUILD_DIR = ../build/


all: snake

snake: snake.o game_field.o main.o
	${COMPILER} ${FLAGS} snake.o game_field.o main.o -o ${BUILD_DIR}snake
	rm -rf *.o

snake.o:
	${COMPILER} ${FLAGS} -c snake_lib/snake.c

game_field.o:
	${COMPILER} ${FLAGS} -c game_field_lib/game_field.c

main.o:
	${COMPILER} ${FLAGS} -c main.c

test:
	${COMPILER} -c snake_lib/snake.c game_field_lib/game_field.c main.c
	${COMPILER} snake.o game_field.o main.o -o test_snake
	rm -rf *.o

clean:
	rm -rf *.o ../build/snake


