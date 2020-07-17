CC = gcc

SRCS = CircularQueue.c CircularQueueMain.c

EXTRAINCDIRS = CircularQueue.h

BUILDDIR = buildDir

TARGET = CircularQueue

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INC = $(patsubst %,-I%, $(EXTRAINCDIRS))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})


$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

clean:
	rm -rf $(BUILDDIR)

SUFFIXES: .c .o