
TARGET = sc

CC = gcc

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)


$(TARGET):	$(OBJS)
	$(CC) -Wall -o $@ $^

$(OBJS):	$(SRCS)
	$(CC) -Wall -c $^

clean:
	rm $(TARGET) $(OBJS)

wc:
	wc $(SRCS)
