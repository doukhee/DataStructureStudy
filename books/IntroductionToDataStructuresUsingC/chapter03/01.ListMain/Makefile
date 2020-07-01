CC = gcc

SRCS = ArrayList.c \
ListMain.c

EXTRAINCDIRS = ArrayList.h

BUILDDIR = buildDir

TARGET = ArrayList

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




