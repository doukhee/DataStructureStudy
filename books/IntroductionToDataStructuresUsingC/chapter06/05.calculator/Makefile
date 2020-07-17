CC = gcc

SRCS = InfixCalculator.c InfixCalculatorMain.c InfixToPostfix.c PostCalculator.c ListBaseStack.c

EXTRAINCDIRS = InfixCalculator.h InfixToPostfix.h PostCalculator.h ListBaseStack.h

BUILDDIR = buildDir

TARGET = InfixCalculator

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

C_INC = $(patsubst %,-I%,$(EXTRAINCDIRS))

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