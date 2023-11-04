CC = gcc
CFLAGS = -Wall
SRC_DIR = Graph/src/
INCLUDE_DIR = Graph/inc
SOURCES = $(SRC_DIR)main.c $(SRC_DIR)graph.c
OUTPUT = main

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SOURCES) -o $(OUTPUT)

lint:
	cppcheck --enable=all $(SOURCES)

clean:
	rm $(OUTPUT)
