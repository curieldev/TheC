OUTDIR = ../../build

SOURCES = $(wildcard *.c)
EXECS	= $(addprefix $(OUTDIR)/,$(basename $(SOURCES)))
OBJS 	= $(SOURCES:.c=.o)

CC		:= gcc
CFLAGS  += -Wall
LDLIBS	+= -lm
CSTD	?= -std=c99


all: $(EXECS)

$(OUTDIR)/%: %.o
	@mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) $(LDLIBS) $(CSTD) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(LDLIBS) $(CSTD) -c $< -o $@

.SECONDARY: $(OBJS)
