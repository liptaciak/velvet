CC = clang 
CFLAGS = -fPIC -Iinclude -Wall -Wextra -Werror -pedantic -std=c11

SRC = $(wildcard *.c ./src/*.c) 
OBJ = $(SRC:.c=.o) 

all: main velvet.so 

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ) 

velvet.so: $(OBJ) 
	$(CC) $(CFLAGS) -shared -o velvet.so $(OBJ) 

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	rm -f *.o ./src/*.o main velvet.so
