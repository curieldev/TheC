SRC_DIR = src
CC		:= gcc
CFLAGS  += -Wall
CSTD	?= -std=c99

SRCS = $(wildcard $(SRC_DIR)/*.c)
BINS = $(notdir $(patsubst %.c, %, $(SRCS)))

all: $(BINS)

$(BINS): %: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o build/$@

clean: 
	rm build/*

print-%  :
	@echo $* = $($*)
