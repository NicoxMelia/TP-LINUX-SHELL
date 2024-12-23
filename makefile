COMPILER = gcc
FLAGS = -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11
FILES = rdproc.c functions.c kernelvar.c polling.c process.c stadistic.c
NAME = rdproc

all :
	$(COMPILER) $(FLAGS) -o $(NAME) $(FILES)