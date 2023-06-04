
CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = `pkg-config --libs gtk+-3.0`
SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = InfoSys-v1.0-rc3-x86_64-Ubuntu

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.o
	$(CC) $(CFLAGS) $(OBJECTS) main.o -o $(EXECUTABLE) $(LIBS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ `pkg-config --cflags gtk+-3.0`

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o `pkg-config --cflags gtk+-3.0`

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) main.o
	
start:
	./$(EXECUTABLE)
