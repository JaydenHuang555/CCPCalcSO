NAME=calc
SRC=$(shell ls *.cpp)

all:
	gcc -o $(NAME) $(SRC) -g -Iinculde

