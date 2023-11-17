SRC_DIR = src
OUT_DIR = build
CC		:= gcc
CFLAGS  += -Wall
CSTD	?= -std=c99

SRCS = $(wildcard $(SRC_DIR)/*.c)
BINS = $(notdir $(patsubst %.c, %, $(SRCS)))

all: $(BINS)

$(BINS): %: $(SRC_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $< -o $(OUT_DIR)/$@

clean: 
	rm -r $(OUT_DIR)

print-%:
	@echo $* = $($*)
