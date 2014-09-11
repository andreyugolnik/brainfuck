CC=g++
CFLAGS=-O2 -c -Wall -I/usr/include
LDFLAGS=-s

SOURCES= \
	src/main.cpp \
	src/parser.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bfi

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

