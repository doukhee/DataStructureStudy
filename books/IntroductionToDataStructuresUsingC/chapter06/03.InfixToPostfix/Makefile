CC = gcc

SRCS = InfixToPostfix.c InfixToPostfixMain.c ListBaseStack.c

EXTRAINCDIRS = InfixToPostfix.h ListBaseStack.h

BUILDDIR = buildDir

TARGET = InfixToPostfix

C_INC = $(patsubst %,-I%,$(EXTRAINCDIRS))

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

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