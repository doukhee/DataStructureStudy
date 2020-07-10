CC = gcc

SRCS = DBLinkedList.c DBLinkedListMain.c

EXTRAINCDIRS = DBLinkedList.h 

C_INC = $(patsubst %,-I%,$(EXTRAINCDIRS))

TARGET = DBLinkedList

BUILDDIR = buildDir

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.c=.o))

all: clean creatdirs build

creatdirs:
	$(shell mkdir ${BUILDDIR})

$(COBJS): $(BUILDDIR)/%.o : %.c
	$(CC) $(C_INC) -o $@ -c $<

build: $(COBJS)
	$(CC) -o $(BUILDDIR)/$(TARGET) $^

clean:
	rm -rf $(BUILDDIR)

SUFFIXES: .c .o