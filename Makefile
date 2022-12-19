CC=clang
CFLAGS=-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LDLIBS=-lcrypt -lm

%.o : %.c
	$(CC) -c $(CFLAGS)  $< -o $@