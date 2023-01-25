CC = clang
CFLAGS = -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wsign-compare

LDLIBS = -lm 

SRCS != basename --suffix=.c *.c
INC = inc/queue.o inc/validate_pin.o
EXTRA = extra/dna_to_rna extra/longest extra/stack extra/test extra/tui

all:$(SRCS) $(EXTRA) $(INC)

inc/%.o:inc/%.c
	$(CC) -c $(CFLAGS) $< -o bin/`basename $@`

extra/%:extra/%.c
	$(CC) $(CFLAGS)  $< -o bin/`basename $@` -lm -lcriterion -lncurses

%.o : %.c
	$(CC) -c $(CFLAGS)  $< -o bin/$@

% : %.c
	$(CC) $(CFLAGS)  $< -o bin/$@ $(LDLIBS)

clean:
	rm -rf bin/*
	rm -rf *.o
