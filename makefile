CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: test_operations test_push_swap

test_operations: test_operations.c operations.c
	$(CC) $(CFLAGS) -o test_operations test_operations.c operations.c
	./test_operations

test_push_swap: test_push_swap.c push_swap.c
	$(CC) $(CFLAGS) -o test_push_swap test_push_swap.c test_push_swappush_swap.c
	./test_push_swap

clean:
	rm -f test_operations test_push_swap
