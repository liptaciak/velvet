OUTPUT = velvet.so

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

CC = clang
CFLAGS = -I include -Wall -Wextra -pedantic -Werror -std=c11
LDFLAGS = -shared

all: $(OUTPUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(OUTPUT): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f ./src/*.o *.o a.out velvet.so