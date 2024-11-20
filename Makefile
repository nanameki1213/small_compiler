
TARGET = sc

CC = gcc

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)


$(TARGET):	$(OBJS)
	$(CC) -o $@ $^

$(OBJS):	$(SRCS)
	$(CC) -c $^

clean:
	rm $(TARGET) $(OBJS)

wc:
	wc $(SRCS)
