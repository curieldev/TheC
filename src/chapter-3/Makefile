OUTDIR	= ../../bin

SOURCES = $(wildcard *.c)
BINS	= $(addprefix $(OUTDIR)/,$(basename $(SOURCES)))
OBJS 	= $(SOURCES:.c=.o)

CC		= gcc
CSTD	= -std=c99
LDLIBS	= -lm
LDFLAGS =

# LDLIBS should be placed after source files
CFLAGS  = -Wall $(CSTD) $(LDLIBS) $(LDFLAGS)


all: $(BINS)

$(OUTDIR)/%: %.o | $(OUTDIR)
	$(CC) $< -o $@ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(OUTDIR):
	@mkdir -p $@

.SECONDARY: $(OBJS)
