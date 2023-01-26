CC = clang
CFLAGS = -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -Wsign-compare

LDLIBS = -lm

SRCS != basename --suffix=.c *.c
INC != ls inc/*.c | sed "s/c$$/o/g"
EXTRA != ls extra/*.c | sed "s/.c$$//g"

all:$(INC) $(SRCS) $(EXTRA)

inc/%.o:inc/%.c
	$(CC) -c $(CFLAGS) $< -o $@

extra/%:extra/%.c
	$(CC) $(CFLAGS)  $< -o bin/`basename $@` $(LDLIBS) -lcriterion -lncurses

%.o : %.c
	$(CC) -c $(CFLAGS)  $< -o bin/$@

% : %.c
	$(CC) $(CFLAGS)  $< $(INC) -o bin/$@ $(LDLIBS)

clean:
	rm -rf bin/*
	rm -rf *.o
	rm -rf inc/*.o
