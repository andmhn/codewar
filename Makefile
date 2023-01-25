CC=clang
CFLAGS=-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wsign-compare

LDLIBS=-lm # -lcriterion -lncurses

bin/% : %.c
	$(CC) -c $(CFLAGS)  $< -o $@
