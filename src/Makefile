CC=g++
CFLAGS=-c -Wall
LDFLAGS=-ld3d11 -ldxgi -luser32 -lgdi32

SOURCES=./src/dxsx.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=FireboyandWatergirl.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
