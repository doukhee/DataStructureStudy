CC = gcc

SRCS = ListBaseQueue.c ListBaseQueueMain.c

EXTRAINCDIRS = ListBaseQueue.h

TARGET = ListBaseQueue

C_INC = $(patsubst %,-I%, $(EXTRAINCDIRS))

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

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