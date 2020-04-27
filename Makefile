CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp function.cpp menu.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=laba1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
