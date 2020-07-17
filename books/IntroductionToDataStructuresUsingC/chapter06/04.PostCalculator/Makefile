CC = gcc

SRCS = ListBaseStack.c PostCalculator.c PostCalculatorMain.c

EXTRAINCIDRS = ListBaseStack.h PostCalculator.h

BUILDDIR = bulidDir

TARGET = PostCalCulator

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INC = $(patsubst %,-I%, $(EXTRAINCIDRS))

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
