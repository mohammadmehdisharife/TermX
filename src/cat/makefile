CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = cat
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
