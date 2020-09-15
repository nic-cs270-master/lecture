# Macros
CC = gcc
CFLAGS =
# CFLAGS = -g
# CFLAGS = -D NDEBUG
# CFLAGS = -D NDEBUG -O
# CFLAGS = -std=c90 -Wall -Wextra

%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Dependency rules for non-file targets
all: testintmath
clobber: clean
	rm -f *~ \#*\#
clean:
	rm -f testintmatch *.o

# Dependency rules for file targets
testintmath: testintmath.o intmath.o
	$(CC) $(CFLAGS) $< intmath.o -o $@
testintmath.o: intmath.h
intmath.o: intmath.h
