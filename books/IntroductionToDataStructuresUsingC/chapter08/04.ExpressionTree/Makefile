CC = gcc

SRCS = BinaryTree2.c ExpressionTree.c ListBaseStack.c ExpressionTreeMain.c

C_HEADER = BinaryTree2.h ExpressionTree.h ListBaseStack.h

C_INC = $(patsubst %,-I%, $(C_HEADER))

BUILDDIR = buildDir

TARGET = ExpressionTree

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir $(BUILDDIR))

build: $(COBJS)
	$(CC) $(C_INC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)

.SUFFIXES: .c .o