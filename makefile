CC = gcc
CFLAGS = -Wall -std=c11

all: project10_guests

project10_guests: guest.o read_line.o project10_guests.o
	$(CC) $(CFLAGS) -o project10_guests guest.o read_line.o project10_guests.o

guest.o: guest.c guest.h
	$(CC) $(CFLAGS) -c guest.c

read_line.o: read_line.c read_line.h
	$(CC) $(CFLAGS) -c read_line.c

project10_guests.o: project10_guests.c guest.h read_line.h
	$(CC) $(CFLAGS) -c project10_guests.c

clean:
	rm -f *.o project10_guests
