CC = gcc
CFLAGS = -Wall -O2
SRC_DIR = src
BIN_DIR = bin

SOURCES := $(wildcard $(SRC_DIR)/*.c)

BINARIES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

all: $(BINARIES)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)/*