
LIBC = /usr/lib/libc.a
obj  = read_file.o notify_send.o scalpd.o list.o timecompare.o add.o trigger_update.o del.o rm.o append.o prune.o help.o read_time.o prompt.o pseloe.o change.o move.o copy.o Itoa/itoa.o
headers = scalp.h config.h
mobj = scalp.o $(obj)
tobj = test/test.o $(obj)

LDFLAGS += -static -s -z norelro -z noseparate-code

build: scalp

check: test/test
	@cd test/ ; ./test

Itoa/itoa.o:
	make -C Itoa -f Makefile

config.h: config.def.h
	cp -i config.def.h config.h
	@echo "To change the configuration, edit config.h"

scalp: $(mobj) $(LIBC)
	ld $(LDFLAGS) -o $@ $^

test/test: $(tobj) $(LIBC)
	ld $(LDFLAGS) -o $@ $^

clean:
	rm -f scalp test/test *.o test/*.o
	make -C Itoa -f Makefile clean

install: scalp
	install scalp /usr/bin/
	install scalp.1 /usr/share/man/man1/

.PHONY: build check install clean

all: build check install clean
