target  = librarian.exe
sources = librarian.c borrow.c return.c search.c
obj     = $(sources:.c=.o)
CC      = gcc
CFLAGS  = -Wall -Wextra

$(target): $(obj)
	$(CC) $^ -o $@

%.o: %.c books.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-del /Q $(obj) $(target) 2>NUL

.PHONY: clean