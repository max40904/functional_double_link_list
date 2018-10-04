EXEC:= mem_test
CC = gcc
CFLAG = -Wall -std=c99 
DEFLAG = -DDEBUG
ifeq ($(CC),gcc)
	SRCS:=$(shell ls *.c)
	OBJS:=$(SRCS:.c=.o)
	TYPE = %.c
else
	SRCS:=$(shell ls *.cpp)
	OBJS:=$(SRCS:.cpp=.o)
	TYPE = %.cpp
endif

all: $(EXEC)
$(EXEC):$(OBJS)
	$(CC) $(CFLAG) $(DEFLAG) -o $@ $(OBJS)
%.o:$(TYPE)
	$(CC) $(CFLAG) $(DEFLAG) -c  -o $@ $<
	

dep:
	$(CC) $(CFLAG) & -M $(SRCS) > depend

clean:
	rm -f $(EXEC) depend
	rm -f $(EXEC) 
	rm -f *.o

	









