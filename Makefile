CHAPTERS = $(wildcard src/*)
OUTDIR = build

all: $(CHAPTERS)

$(CHAPTERS): %:
	@make --no-print-directory -C $@

clean:
	rm -r $(OUTDIR)
	rm $(addsuffix /*.o, $(CHAPTERS))

print-%:
	@echo $* = $($*)

.PHONY: all clean print-% $(CHAPTERS)

