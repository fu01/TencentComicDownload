.PHONY: all
all:
	cd src; make; mv TencentComic ../

.PHONY: clean
clean:
	cd src; make clean
