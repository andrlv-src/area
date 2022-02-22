CC=gcc
CFLAGS=-c -Wall -ggdb -std=c11
SOURCES=main.c area.c

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=area

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rfv *.o area
