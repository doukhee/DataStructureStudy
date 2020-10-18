CC = gcc

SRCS = BinaryTreeMain.c BinaryTree.c

C_HEADER = BinaryTree.h

C_INC = $(patsubst %,-I%, $(C_HEADER))

TARGET = BinaryTreeMain

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir $(BUILDDIR))

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

$(COBJS):$(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)

.SUFFIXES: .c .o