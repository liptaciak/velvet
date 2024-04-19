OUTPUT = velvet.so

SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -I include -Wall -Wextra -pedantic -std=c11
LDFLAGS = -shared

all: $(OUTPUT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f *.o a.out velvet.so