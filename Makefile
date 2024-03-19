CHAPTERS	= $(wildcard src/*)
OUTDIR		= bin
MAKEFLAGS	= --no-print-directory

all: $(CHAPTERS)

$(CHAPTERS): %:
	@$(MAKE) --no-print-directory -C $@

clean:
	rm -r $(OUTDIR)
	rm $(addsuffix /*.o, $(CHAPTERS))

print-%:
	@echo $* = $($*)

.PHONY: all clean print-% $(CHAPTERS)

