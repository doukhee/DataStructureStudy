CC = gcc

SRCS = ArrayBaseStack.c ArrayBaseStackMain.c

EXTRAINCDIR = ArrayBaseStack.h

BUILDDIR = buildDir

TARGET = ArrayBaseStack

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INC = $(patsubst %,-I%,$(EXTRAINCDIR))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

clean:
	rm -rf $(BUILDDIR)


SUFFIXES: .c .o