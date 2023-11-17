CC = gcc
CFLAGS = -Wall -I$(INCLUDE_DIR) --std=c99
SRC_DIR = Graph/src/
INCLUDE_DIR = Graph/inc
SOURCES = $(SRC_DIR)main.c $(SRC_DIR)graph.c
OUTPUT = main

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT)

lint:
	cppcheck --enable=all --std=c99 -I$(INCLUDE_DIR) --suppress=missingIncludeSystem $(SOURCES)

clean:
	rm $(OUTPUT)

