CC      := gcc
CFLAGS  := 

SRC     := main.c history.c config.c utils.c
OBJS    := history.o config.o utils.o
TARGET  := line

LIBS    := -lraylib -lm
LDFLAGS := -L.

HEADERS := raylib.h history.h config.h utils.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c $(HEADERS)

clean:
	rm -f $(TARGET) *.o
